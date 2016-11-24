(function ($) {

  var svgHhasClass = function ($this, className) {
    return new RegExp('(\\s|^)' + className + '(\\s|$)').test($this.attr('class'));
  };

  var svgAddClass = function ($this, className) {
    if (!svgHhasClass($this, className)) {
      $this.attr('class', $this.attr('class') + ' ' + className);
    }
  };

  var svgRemoveClass = function  ($this ,className)  {
    $this.attr ( 'class', '');
  }

  /*сохранить svg*/
  var saveHomePlanComplex = function(obj) {
    console.log(obj);
    $.ajax({
      url: '/add_plan_complex/edit_svg',
      type: 'POST',
      async: false,
      data: {
        obj: obj
      },
      success: function(response) {
        console.log('Сохранено');
      },
      error: function(response) {
        alert('false');
      }
    });
  }

  Drupal.behaviors.mark_pictureComplexInit = {
    attach: $(function () {

      /*Функция обработка кнопки "Отметить очереди строительства на плане ЖК"*/
      var bottomNoteQueuePlan = function () {
        var complexNid = $('#add-queue-plan').data('id-complex');
        $.ajax({
          url: '/add_plan_complex',
          type: 'POST',
          data: {
            nid: complexNid
          },
          success: function (response) {
            var object = JSON.parse(response);
            if (object.img) {
              $('.div-plan-complex-queue').html('');
              $('.div-plan-complex-queue').html(object.img);
              $('.div-plan-complex-queue').attr('data-file', object.file);
            }
          },
          error: function (response) {
            alert('false');
          }
        });
      }

      /*Функция обработка клик по инструменту*/
      var toolAddMark = function (tool, div) {
        $(tool).click(function () {
          if ($(this).hasClass('tool-add-active')) {
            $(this).removeClass('tool-add-active');
            $('.' + div).removeClass(div + '-active');

            // Удаление несохраненных параметров
            if ($('.current_poligon').attr('data-queue') == undefined) {
              $('.current_poligon').removeAttr('data-queue');
              $('.current_poligon').removeAttr('data-quarter');
              $('.current_poligon').removeAttr('data-year');
            }

            $('.current_poligon').removeAttr('class');
            $('.complex-window-dialog').remove();
          }
          else {
            $(this).addClass('tool-add-active');
            $('.' + div).addClass(div + '-active');
          }
        })
      }

      // Функция добавления параметров в svg-файл
      function windowDialog(queueNumber, deadlineQuarter, deadlineYear) {

        $('.complex-window-dialog').remove();

        queueNumber = queueNumber ? queueNumber : '';
        deadlineQuarter = deadlineQuarter ? deadlineQuarter : '';
        deadlineYear = deadlineYear ? deadlineYear : '';

        var
          htmlDialog = '<div class="complex-window-dialog" style="height: 100px; position: absolute; left: 100%; top: 0% ; z-index: 100;">' +
            '<p><b>Номер очереди</b></p>' +
            '<input type="text" id="queue_number" placeholder="Номер" style="width: 65px" value="'+queueNumber+'">' +
            '<br><p><b>Срок сдачи</b></p><br>' +
            '<input type="text" id="deadline_quearter" placeholder="Квартал" value="'+deadlineQuarter+'"style="width: 65px">&nbsp;&nbsp;' +
            '<input type="text" id="deadline_year" value="'+deadlineYear+'" placeholder="Год" style="width: 65px">' +
            '<a href="#href" class="save-complex-queue">сохранить</a>&nbsp;&nbsp;' +
            '<a href="#href" class="del-complex-queue">удалить</a>';

        $('.div-plan-complex-queue').append(htmlDialog);
      }

      // Сохранение параметров в svg
      $(document).on('click','.save-complex-queue', function () {
        var queueNumber = $('#queue_number').val(),
          deadlineQuarter = $('#deadline_quearter').val(),
          deadlineYear = $('#deadline_year').val();

        $('.current_poligon').attr('data-queue', queueNumber);
        $('.current_poligon').attr('data-quarter', deadlineQuarter);
        $('.current_poligon').attr('data-year', deadlineYear);

        $('.current_poligon').attr('class', 'svg-plan-queue');
        $('.complex-window-dialog').remove();

        window.polygon = null;
      });

      // Сохранение svg на сервер
      $(document).on('click', '#add-queue-plan-save', function () {
        var file = $('.div-plan-complex-queue').data('file'),
          svg = $('.div-plan-complex-queue').html(),
          obj = [{
            file: file,
            svg: svg
          }];

        saveHomePlanComplex(obj);
      })

      // Удаление паремтров из svg
      $(document).on('click', '.del-complex-queue', function () {
        $('.current_poligon').removeAttr('data-queue');
        $('.current_poligon').removeAttr('data-quarter');
        $('.current_poligon').removeAttr('data-year');

        $('.current_poligon').removeAttr('class');

        $('.complex-window-dialog').remove();
      })

      /*Функция добавления класа выбронному полигону svg*/
      var addClassPolygon = function ($this) {
        var planQueue = 'svg-plan-queue',
          currentPoligon = 'current_poligon';

        var queueNumber = $this.attr('data-queue'),
          deadlineQuarter = $this.attr('data-quarter'),
          deadlineYear = $this.attr('data-year');

        // Если класс уже имеется
        if (svgHhasClass($this, currentPoligon)) {

          $this.attr('class', planQueue);

          // Удаление класса
          if ($this.attr('data-queue') == undefined) {
            $this.attr('class', '');

          }
        }
        // Если класс не имеется
        else {
          // Удаление класса с прежнего полтгона

          // Удаление класса
          if (window.polygon) {
            window.polygon.attr('class', planQueue);

            if (window.polygon.attr('data-queue') == undefined) {
              window.polygon.attr('class', '');
            }
          }

          // Добавление класса текущему полигону
          svgAddClass($this, planQueue);
          svgAddClass($this, currentPoligon);

          windowDialog(queueNumber, deadlineQuarter, deadlineYear, 0, null);
        }

        // Запись ссылки на полигон
        window.polygon = $this;
      }

      /*Функция обработка клик по плану комплекса*/
      var clickPlanComplex = function () {
        $(document).on('click', '.div-plan-complex-queue-active svg polygon', function () {
          addClassPolygon($(this));
        });
        $(document).on('click', '.div-plan-complex-queue-active svg path', function () {
          addClassPolygon($(this));
        });
        $(document).on('click', '.div-plan-complex-queue-active svg rect', function () {
          addClassPolygon($(this));
        });
      }

      // Клик по Отметить очереди строительства
      $('#add-queue-plan').click(function () {
        bottomNoteQueuePlan();
        console.log('ok');
      });

      // Клик по инструменту
      toolAddMark('.tool-add-queue', 'div-plan-complex-queue');

      clickPlanComplex();
    })
  }

  Drupal.behaviors.mark_pictureHomeInit = {
    attach: $(function() {

      var queue_home = false;

      /*Функция обработка кнопки "Отметить дом на плане ЖК"*/
      var bottomNoteHomePlan = function () {
        var complex = $('#edit-field-home-complex-und');
        if (complex.val() == '_none') {
          $('.div-plan-complex').html('');
          $('.div-plan-complex').html('<p class="error-add-complex">Выбирете жилой комплекс</p>');
        }
        else {
          $.ajax({
            url: '/add_plan_complex',
            type: 'POST',
            data: {
              nid: complex.val()
            },
            success: function(response) {
              var object = JSON.parse(response);
              if(object.img) {
                $('.div-plan-complex').html('');
                $('.div-plan-complex').html(object.img);
                $('.div-plan-complex').attr('data-file', object.file);
              }
            },
            error: function(response) {
              alert('false');
            }
          });
        }
      }

      /*Функция обработка кнопки "Отметить секции"*/
      var bottomNoteSectionsHomePlan = function () {
        if($('.form-item-field-home-plan-und-0 .file a').length > 0) {
          var home_plan = $('.form-item-field-home-plan-und-0 .file a').html();

          $('.div-plan-home').html('');

          $.ajax({
            url: '/add_plan_home',
            type: 'POST',
            data: {
              file: home_plan
            },
            success: function(response) {
              if(response) {
                var object = JSON.parse(response);
                $('.div-plan-home').html(object.img)
                $('.div-plan-home').attr('data-file', object.file);
              }
            },
            error: function(response) {
              alert('false');
            }
          });
        }
        else {
          $('.div-plan-home').html('');
          $('.div-plan-home').append('Загрузите план дома!!!');
        }
      }

      /*Функция обработка клик по инструменту*/
      var toolAddMark = function (tool, div) {
        $(tool).click(function() {
          if (tool == '.tool-add-queue-home') {

            if (queue_home) {
              queue_home = false;
            }
            else {
              queue_home = true;
            }

            console.log('s '+tool);
            console.log('s '+queue_home);
          }
          console.log(queue_home);
          console.log(tool);
          if($(this).hasClass('tool-add-active')) {
            $(this).removeClass('tool-add-active');
            $('.'+div).removeClass(div + '-active');

            // Удаление несохраненных параметров
            $('.current_poligon').removeAttr('class');
            $('.home-window-dialog').remove();
          }
          else {
            $(tool).addClass('tool-add-active');
            $('.'+div).addClass(div + '-active');
          }
        })
      }

      /*random*/
      var getRandomInt = function(min, max) {
        return Math.floor(Math.random() * (max - min)) + min;
      }

      /*      ---------------------------------*/

      // Функция добавления параметров в svg-файл
      function windowDialog(checkPassive) {
        checkPassive = checkPassive ? checkPassive : '';

        $('.home-window-dialog').remove();

        var
          htmlDialog = '<div class="home-window-dialog" style="height: 80px; position: absolute; left: 100%; top: 0% ; z-index: 100;">' +
            '<p><b>Акивность</b></p><br>' +
            '<input type="checkbox" id="home-passive" '+checkPassive+'>Сделать неактивным<br>' +
            '<a href="#href" class="save-home">сохранить</a>&nbsp;&nbsp;' +
            '<a href="#href" class="del-home">удалить</a>';

        $('.div-plan-complex').append(htmlDialog);
      }

      // Сохранение параметров в svg
      $(document).on('click','.save-home', function () {

        // Если элемент пассивный
        if ($('#home-passive').is(':checked')) {

          $('.current_poligon').removeAttr('id');
          $('.current_poligon').attr('class','svg-home-passive');
        }
        // Если элемент активный
        else {
          var adminClass = 'svg-admin-class',
            fieldComplexPlan = $('#edit-field-lage-plan-complex-und-0-value'),
            hoverClass = 'svg-hover-class',
            objClass = 'complex-plan',
            homeId = window.location.href.split('/')[5],
            complexID = $('#edit-field-home-complex-und').val(),
            homeClass = 'complex-'+complexID+'-home-'+homeId;

          $('.current_poligon').attr('id', homeClass);
          $('.current_poligon').attr('class', adminClass+' '+hoverClass+' '+objClass);

          fieldComplexPlan.val(homeClass);
        }

        // Удаление диалогового окна
        $('.home-window-dialog').remove();

        window.polygon = null;
      });

      // Удаление паремтров из svg
      $(document).on('click', '.del-home', function () {
        $('.current_poligon').removeAttr('id');

        $('.current_poligon').removeAttr('class');

        $('.home-window-dialog').remove();
      })

      /*----------------------*/

      /*Функция добавления класа выбронному полигону svg*/
      var addClassPolygon = function ($this) {

        var adminClass = 'svg-admin-class',
          currentPoligon = 'current_poligon',
          thisClass = $this.attr('class'),
          checkPassive;

        if (thisClass) {
          if (thisClass.indexOf('svg-home-passive') + 1) {
            checkPassive = 'checked';
          }
        }

        /*hoverClass = 'svg-hover-class',
         objClass = 'complex-plan';*/
        /*homeId = window.location.href.split('/')[5],
         complexID = $('#edit-field-home-complex-und').val(),
         homeClass = 'complex-'+complexID+'-home-'+homeId;*/

        // Если класс уже имеется
        if(svgHhasClass($this, currentPoligon)) {
          $this.attr('class','');

          $('.home-window-dialog').remove();
        }
        // Если класс не имеется
        else {
          if (window.polygon) {
            window.polygon.attr('class', '');
          }

          /*$this.attr('id', homeClass);
           svgAddClass($this, adminClass+' '+hoverClass+' '+objClass);
           fieldComplexPlan.val(homeClass);*/

          svgAddClass($this, adminClass);
          svgAddClass($this, currentPoligon);

          windowDialog(checkPassive);
        }

        window.polygon = $this;
      }

      /*Функция обработка клик по плану комплекса*/
      var clickPlanComplex = function () {
        $(document).on('click', '.div-plan-complex-active svg polygon', function(){
          addClassPolygon($(this));
        });
        $(document).on('click', '.div-plan-complex-active svg path', function(){
          addClassPolygon($(this));
        });
        $(document).on('click', '.div-plan-complex-active svg rect', function(){
          addClassPolygon($(this));
        });
      }

      /*Функция обработка клик по плану дома*/
      var clickPlanHome = function () {
        $(document).on('click', '.div-plan-home-active svg polygon', function(){
          addClassPolygonHome($(this));
        });
        $(document).on('click', '.div-plan-home-active svg path', function(){
          addClassPolygonHome($(this));
        });
        $(document).on('click', '.div-plan-home-active svg rect', function(){
          addClassPolygonHome($(this));
        });
      }

      var addSectionsDialog = function (tool, element, mark, flag, $this, checkPassive) {
        checkPassive = checkPassive ? checkPassive : '';

        if ($(tool).hasClass('tool-add-active')) {

          if(flag === true) {
            var num = $this.attr('id').split('-')[0],
              value = $("#edit-field-home-section-und-"+num+"-field-number-section-und-0-value").val(),
              input = '<input type="text" class="form-text" id="dialog-number-section" value="'+value+'">';
            console.log(value);

          }
          else {
            input = '<input type="text" class="form-text" id="dialog-number-section">'
          }
          $('.'+element).append('<div class="dialog" style="position: absolute; left:100%; top:0 ; z-index: 100;"> ' +
            'Номер секции'+
            input + '<input type="checkbox" id="section-passive" '+checkPassive+'>Сделать неактивной<br>' +
            '<a class="save-'+mark+'" data-id="'+num+'">Сохранить</a> ' +
            '<a class="delete-section" data-id="'+num+'">Удалить</a> ' +
            '<p class="error-dialog"></p>'+
            '</div>');

          $(tool).trigger('click');
        }
        else {
          return 0;
        }
      }

      // Функция добавления параметров Очереди строителства в svg
      var addQueueHomeDialog = function (queueNumber, deadlineQuarter, deadlineYear) {
        $('.complex-window-dialog').remove();

        queueNumber = queueNumber ? queueNumber : '';
        deadlineQuarter = deadlineQuarter ? deadlineQuarter : '';
        deadlineYear = deadlineYear ? deadlineYear : '';

        var
          htmlDialog = '<div class="complex-window-dialog" style="height: 100px; position: absolute; left: 100%; top: 0% ; z-index: 100;">' +
            '<p><b>Номер очереди</b></p>' +
            '<input type="text" id="queue_number" placeholder="Номер" style="width: 65px" value="'+queueNumber+'">' +
            '<br><p><b>Срок сдачи</b></p><br>' +
            '<input type="text" id="deadline_quearter" placeholder="Квартал" value="'+deadlineQuarter+'"style="width: 65px">&nbsp;&nbsp;' +
            '<input type="text" id="deadline_year" value="'+deadlineYear+'" placeholder="Год" style="width: 65px">' +
            '<a href="#href" class="save-home-queue">сохранить</a>&nbsp;&nbsp;' +
            '<a href="#href" class="del-home-queue">удалить</a>';

        $('.div-plan-home').append(htmlDialog);

        console.log('круть!')
      }

      var saveDialogSections = function($this) {
        console.log('ok');
        var id_sec = $('#dialog-number-section').val(),
          i = 0,
          homeId = window.location.href.split('/')[5],
          complexID = $('#edit-field-home-complex-und').val(),



          id_sec = id_sec.replace(/\./gi, "_");
        id_sec = id_sec.replace(/\-/gi, "_");
        $('#edit-field-lage-plan-complex-und-0-value').val('complex-'+complexID+'-home-'+homeId);
        var homeID = $('#edit-field-lage-plan-complex-und-0-value').val();

        if ($this.data('id') !== 'undefined') {
          i = $this.data('id');
        }
        else {
          while(true) {
            if($('#edit-field-home-section-und-'+i+'-field-number-section-und-0-value').val() == '') {
              break;
            }
            else {
              i++;
            }
          }
        }

        if($('.section-'+id_sec).length > 0) {
          $('.dialog .error-dialog').html('Секция уже существует');
        }
        else if(id_sec == '') {
          $('.dialog .error-dialog').html('Введите номер');
        }
        else if(homeID == '') {
          $('.dialog .error-dialog').html('Отметьте дом на плане ЖК');
        }
        else {
          window.globalSections.attr('id', i+'-'+homeID+'-section-'+id_sec);
          $('#edit-field-home-section-und-'+i+'-field-number-section-und-0-value').val(id_sec.replace(/\_/gi, "."));
          $('#edit-field-home-section-und-'+i+'-field-lage-plan-home-und-0-value').val(i+'-'+homeID+'-section-'+id_sec);
          $('.dialog').remove();
        }
      };

      var deleteDialogSections = function($this) {
        var id_sec = $('#dialog-number-section').val(),
          i = 0,
          homeID = $('#edit-field-lage-plan-complex-und-0-value').val(),
          complexID = $('#edit-field-home-complex-und').val();

        if ($this.data('id') !== 'undefined') {
          i = $this.data('id');
          $('#edit-field-home-section-und-'+i+'-field-number-section-und-0-value').val('');
          $('#edit-field-home-section-und-'+i+'-field-lage-plan-home-und-0-value').val('');
          window.globalSections.attr('class', '');
          window.globalSections.attr('id', '');
          $('.dialog').remove();
        }
        else {
          window.globalSections.attr('class', '');
          $('.dialog').remove();
        }
      }

      // Добавление классов к Плану дома
      var addClassPolygonHome = function ($this) {

        // Елси выбранный интсрумет Отметить очередь строительства
        if (queue_home) {

          var planQueue = 'svg-plan-queue',
            currentPoligon = 'current_poligon',
            queueNumber = $this.attr('data-queue'),
            deadlineQuarter = $this.attr('data-quarter'),
            deadlineYear = $this.attr('data-year');

          // Если класс уже имеется
          if (svgHhasClass($this, currentPoligon)) {

            $this.attr('class', planQueue);

            // Удаление класса
            if ($this.attr('data-queue') == undefined) {
              $this.attr('class', '');

            }
          }
          // Если класс не имеется
          else {
            // Удаление класса с прежнего полтгона

            // Удаление класса
            if (window.polygon) {
              window.polygon.attr('class', planQueue);

              if (window.polygon.attr('data-queue') == undefined) {
                window.polygon.attr('class', '');
              }
            }

            // Добавление класса текущему полигону
            svgAddClass($this, planQueue);
            svgAddClass($this, currentPoligon);

            addQueueHomeDialog(queueNumber, deadlineQuarter, deadlineYear);
          }

          // Запись ссылки на полигон
          window.polygon = $this;
        }
        // Если выбранный инструмент Отметить секцию
        else {
          var fieldComplexPlan = $('#edit-field-lage-plan-complex-und-0-value'),
            adminClass = 'svg-admin-class',
            hoverClass = 'svg-hover-class',
            objClass = 'home-plan',
            complexID = $('#edit-field-home-complex-und').val(),
            flag;

          window.globalSections = $this;

          if(svgHhasClass($this, adminClass)) {
            flag = true
          }
          else {
            flag = false
            svgAddClass($this, adminClass+' '+hoverClass+' '+objClass);
          }

            addSectionsDialog('.tool-add-section', 'div-plan-home', 'section', flag, $this);
            svgAddClass($this,'current_poligon');
        }
      }

      $('#add-home-plan').click(function() {
        bottomNoteHomePlan()
      });

      toolAddMark('.tool-add-complex', 'div-plan-complex', 'complex');

      clickPlanComplex();

      /*при клике на сохранить*/
      $(document).on('click','#add-home-plan-save', function(){
        var file = $('.div-plan-complex').data('file'),
          svg = $('.div-plan-complex').html(),
          obj = [{
            file: file,
            svg: svg
          }];

        saveHomePlanComplex(obj);
      });

      $(document).on('click','#save-add-section-plan', function(){
        var file = $('.div-plan-home').data('file'),
          svg = $('.div-plan-home').html(),
          obj = [{
            file: file,
            svg: svg
          }];
        saveHomePlanComplex(obj);
      });

      $('#add-section-plan').click(function() {
        bottomNoteSectionsHomePlan()
      });

      // Клик по инструменту Отметить дом
      toolAddMark('.tool-add-section', 'div-plan-home');

      // Клик по инструменту Очередь строительства
      toolAddMark('.tool-add-queue-home', 'div-plan-home');

      clickPlanHome();

      $(document).on('click', '.save-section', function(){
        // Если секция не активна
        if ($('#section-passive').is(':checked')) {

          $('.current_poligon').removeAttr('id');
          $('.current_poligon').attr('class','svg-home-passive');

          console.log('ok');
          $('.dialog').remove();
        } else {
          var className = $('.current_poligon').attr('class');
          className = className.replace(/\bcurrent_poligon\b/g, '');
          console.log(className);
          $('.current_poligon').attr('class', className);

          console.log('no');
          saveDialogSections($(this));
        }
      })

      $(document).on('click', '.delete-section', function(){
        deleteDialogSections($(this));
      })

      // Сохранение параметров в svg
      $(document).on('click','.save-home-queue', function () {
        var queueNumber = $('#queue_number').val(),
          deadlineQuarter = $('#deadline_quearter').val(),
          deadlineYear = $('#deadline_year').val();

        $('.current_poligon').attr('data-queue', queueNumber);
        $('.current_poligon').attr('data-quarter', deadlineQuarter);
        $('.current_poligon').attr('data-year', deadlineYear);

        $('.current_poligon').attr('class', 'svg-plan-queue');
        $('.complex-window-dialog').remove();

        window.polygon = null;
      });

      // Удаление паремтров из svg
      $(document).on('click', '.del-home-queue', function () {
        $('.current_poligon').removeAttr('data-queue');
        $('.current_poligon').removeAttr('data-quarter');
        $('.current_poligon').removeAttr('data-year');

        $('.current_poligon').removeAttr('class');

        $('.complex-window-dialog').remove();
      })
    })
  }

  Drupal.behaviors.mark_pictureHomeInitApartment = {
    attach: $(function(){
      var addApartmentsPlan = $('#add-apartments-plan');
      var getSvgImage = function(file) {
        var object;
        $.ajax({
          url: '/add_plan_home',
          type: 'POST',
          async: false,
          data: {
            file: file
          },
          success: function(response) {
            if(response) {
              object = JSON.parse(response);

            }
          },
          error: function(response) {
            return false;
          }
        });
        return object;
      }

      function scanFloors () {
        var tablePlanFloors = $('field-plan-floor-values'),
          i = 0,
          j = 0,
          k = 0,
          imageFloors,
          floors,
          floor,
          optionsFloors = {},
          htmlBlock = '',
          sections,
          apartmentValue,
          apartmentObject,
          apartment,
          stringFloor;

        while (1) {
          if ($('#edit-field-plan-floor-und-'+i+'-field-image-plan-floor-und-0-ajax-wrapper .file a').length > 0) {
            imageFloors = $('#edit-field-plan-floor-und-'+i+'-field-image-plan-floor-und-0-ajax-wrapper .file a').attr('href');
            sections = $('#edit-field-plan-floor-und-'+i+'-field-plan-number-section-und-0-value');
            floors = $('#edit-field-plan-floor-und-'+i+'-field-plan-number-floor-und-0-value');
            apartmentValue = $('#edit-field-plan-floor-und-'+i+'-field-apartments-und-0-value');
            stringFloor = floors.val();
            if (sections.val() != '' && floors.val() != '') {
              optionsFloors[i] = [sections.val(), floors.val(), imageFloors, apartmentValue.val()];
            }
            else {
              i++;
              continue;
            }
          }
          else {
            break;
          }
          i++;
        }
        for (floor in optionsFloors) {
          if(optionsFloors[floor][3] != '') {
            apartmentObject = optionsFloors[floor][3];
          }
          var SVG = getSvgImage(optionsFloors[floor][2].split('/')[6]);
          htmlBlock += '<div class="floors-html-block">'+
            '<div class="title-floor-section">Секция: '+optionsFloors[floor][0]+
            '<br>Этажи: '+optionsFloors[floor][1]+'</div>'+
            '<div>' +
            '<img src="http://realty/sites/all/modules/custom/mark_picture/images/centre.png" width="25px" ' +
            'id="tool-'+floor+'" '+
            'class="tool-add tool-add-apartment">'+
            '</div>'+
            '<div class="floor-plan-image" id="plan-'+floor+'" data-file="'+SVG.file+'">'+
            SVG.img;
          htmlBlock +='</div>' +
            '</div>';
          j++;
        }

        return htmlBlock;
      };

      addApartmentsPlan.click(function() {
        $('#add-apartments-plan-form').html('')
          .html(scanFloors());
      });

      $(document).on('click','.tool-add-apartment', function() {
        var toolId;
        if($(this).hasClass('tool-add-active')) {
          $(this).removeClass('tool-add-active');
          toolId = $(this).attr('id').split('-');
          $('#plan-'+toolId[1]).removeClass('floor-plan-image-active');
        }
        else {
          $('.tool-add').removeClass('tool-add-active');
          $('.floor-plan-image').removeClass('floor-plan-image-active');

          $(this).addClass('tool-add-active');

          toolId = $(this).attr('id').split('-');
          $('#plan-'+toolId[1]).addClass('floor-plan-image-active');
        }
      });

      //box filled apartments
      function windowDialog(flag, top, left, id, markId) {
        var planId = id,
          apartmentsValue = $('#edit-field-plan-floor-und-'+id+'-field-apartments-und-0-value'),
          apartments,
          apartmentsValueObj,
          i = 0,
          htmlDialog = '<div class="floor-window-dialog" style="position: absolute; left:'+left+'%; top:'+top+'% ; z-index: 100;">'+
            '<p><b>номер кв</b></p>&nbsp;&nbsp;<p><b>этаж</b></p>'+
            '<div class="form-block-input">';

        for(i ; i < 30 ; i++) {
          htmlDialog += '<input type="text" class="input-form-dialog-apartment" id="apartment-number-'+i+'">&nbsp;&nbsp;' +
            '<input type="text" class="input-form-dialog-apartment" id="floor-number-'+i+'"><br>'
        }

        htmlDialog += '</div>' +
          '<a href="#href" class="save-apartment-plan" id="save-apartment-plan-'+id+'-'+markId+'" >сохранить</a>' +
          '&nbsp;&nbsp;<a href="#href" class="del-apartment-plan" id="del-apartment-plan-'+id+'-'+markId+'">удалить</a></div>';

        planId = 'plan-'+id;
        $('#'+planId).removeClass('floor-plan-image-active');
        $('#'+planId).append(htmlDialog);


        if(apartmentsValue.val().length > 0){
          apartmentsValueObj = jQuery.parseJSON(apartmentsValue.val())
          var jnum = $.inArray(window.apartment.attr('id'), apartmentsValueObj);
          window.apartment.attr('data-jnum', jnum);
        }

        if (flag == true) {

          apartments = window.apartment.attr('id').split('-');
          i = 0;
          for (var j in apartments) {
            if(j == 0) {
              continue;
            }
            else {
              $('#apartment-number-'+i+'').val(apartments[j].split('_')[0]);
              $('#floor-number-'+i+'').val(apartments[j].split('_')[1]);
              i++;
            }
          }
        }
      }

      var addClassPolygonFloor = function ($this) {
        var fieldComplexPlan = $('#edit-field-lage-plan-complex-und-0-value'),
          adminClass = 'svg-admin-class',
          hoverClass = 'svg-hover-class',
          objClass = 'floor-plan',
          complexID = $('#edit-field-home-complex-und').val(),
          flag,
          id = $('.floor-plan-image-active').attr('id').split('-');
        window.apartment = $this;


        if(svgHhasClass($this, adminClass)) {
          flag = true
        }
        else {
          flag = false
          svgAddClass($this, adminClass+' '+hoverClass+' '+objClass);
        }

        windowDialog(flag, 0, 100, id[1], null);
      }

      /*Функция обработка клик по плану дома*/
      var clickPlanFloor = function () {
        $(document).on('click', '.floor-plan-image-active svg polygon', function(){
          addClassPolygonFloor($(this));
        });
        $(document).on('click', '.floor-plan-image-active svg path', function(){
          addClassPolygonFloor($(this));
        });
        $(document).on('click', '.floor-plan-image-active svg rect', function(){
          addClassPolygonFloor($(this));
        });
      }


      //Saving mark
      $(document).on('click', '.save-apartment-plan', function(e){
        var i = 0,
          j = 0,
          id = $(this).attr('id').split('-'),
          apartment = $('#apartment-number-'+i),
          floor = $('#floor-number-'+i),
          windowDialog = $('.floor-window-dialog'),
          top,
          left,
          jsonApartments,
          plan = $('#plan-'+id[3]),
          apartmentsValue = $('#edit-field-plan-floor-und-'+id[3]+'-field-apartments-und-0-value'),
          place,
          homeId = window.location.href.split('/')[5],
          apartmentString = homeId,
          apartmentsValueObj = [],
          lengthArr = 0;

        while(1) {
          apartment = $('#apartment-number-'+i);
          floor = $('#floor-number-'+i);
          if (apartment.val() != undefined && floor.val().length != undefined) {
            apartmentString += '-'+apartment.val()+'_'+floor.val();
          }
          else {
            break;
          }
          i++;
        }

        if (window.apartment.attr('data-jnum') >= 0) {
          if(apartmentsValue.val().length > 0){
            apartmentsValueObj = jQuery.parseJSON(apartmentsValue.val())
            console.log(apartmentsValue.val().length);
            apartmentsValueObj.splice(window.apartment.attr('data-jnum'), 1, apartmentString);
          }

          else {
            apartmentsValueObj.push(apartmentString);
          }
          apartmentsValue.val(JSON.stringify(apartmentsValueObj));
        }
        else {
          if (apartmentsValue.val()) {
            apartmentsValueObj = jQuery.parseJSON(apartmentsValue.val());
            apartmentsValueObj.push(apartmentString);
            lengthArr = apartmentsValueObj.length;
            apartmentsValue.val(JSON.stringify(apartmentsValueObj));
          }
          else {
            apartmentsValueObj.push(apartmentString);
            apartmentsValue.val(JSON.stringify(apartmentsValueObj));
          }
        }

        window.apartment.attr('id', apartmentString);
        $('.floor-window-dialog').remove();
        $('.tool-add').removeClass('tool-add-active');

      });


      clickPlanFloor();


      $(document).on('click', '.del-apartment-plan', function(){
        var id = $(this).attr('id').split('-'),
          apartmentsValue = $('#edit-field-plan-floor-und-'+id[3]+'-field-apartments-und-0-value'),
          apartmentsValueObj;

        apartmentsValueObj = jQuery.parseJSON(apartmentsValue.val());

        apartmentsValueObj.splice(window.apartment.attr('data-jnum'), 1);
        apartmentsValueObj.length > 0 ? apartmentsValue.val(JSON.stringify(apartmentsValueObj)) : apartmentsValue.val('');

        window.apartment.attr('id', '');
        window.apartment.attr('class', '');
        window.apartment.attr('data', '');

        $('.floor-window-dialog').remove();
        $('.tool-add').removeClass('tool-add-active');

      });

      $('#save-apartments-plan').click(function(){
        var i = 0,
          obj=[];

        while(1) {

          if($('#plan-'+i).length > 0) {
            var file = $('#plan-'+i).data('file'),
              svg = $('#plan-'+i).html();
            obj.push({
              file: file,
              svg: svg
            });
            i++;

          }
          else{
            break;
          }
        }
        alert('OK');
        console.log(obj);
        saveHomePlanComplex(obj);
      });

    })
  }

}(jQuery));
