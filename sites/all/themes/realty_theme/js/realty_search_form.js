(function ($) {

  Drupal.behaviors.realtyFormSearch = {
    attach: $(function() {

      var apartmentStatus = function () {

        // при клике по диву, делаем проверку
        $(document).on('click','.dec_checkbox', function(){
          var checkbox = $(this).find('input[type=checkbox]');

          // если чекбокс был активен
          if(checkbox.prop("checked")){

            // снимаем класс с родительского дива
            $(this).removeClass("check_active_result");
            // и снимаем галочку с чекбокса

            checkbox.prop("checked", false);
            // если чекбокс не был активен

            $('#edit-field-status-value option[value=All]').attr('selected', 'selected');
            $('#edit-submit-apartments').trigger('click');
          } else {

            // добавляем класс родительскому диву
            $(this).addClass("check_active_result");

            // ставим галочку в чекбоксе
            checkbox.prop("checked", true);
            $('#edit-field-status-value option[value=1]').attr('selected', 'selected');
            $('#edit-submit-apartments').trigger('click');
          }
        });
      }

      var realtyParkingFilter = function () {
        // чек бокс для бронирования на паковки
        $(document).ready(function(){
          // проверяем, какие чекбоксы активны и меняем сласс для родительского дива
          $('.parking_checkbox').each(function(){
            var checkbox = $(this).find('input[type=checkbox]');
            if(checkbox.prop("checked")) $(this).addClass("check_active_parking");
          });

          // при клике по диву, делаем проверку
          $('.parking_checkbox').click(function(){
            var checkbox = $(this).find('input[type=checkbox]');
            // если чекбокс был активен
            if(checkbox.prop("checked")){
              // снимаем класс с родительского дива
              $(this).removeClass("check_active_parking");
              // и снимаем галочку с чекбокса
              checkbox.prop("checked", false);
              // если чекбокс не был активен
            }else{
              // добавляем класс родительскому диву
              $(this).addClass("check_active_parking");
              // ставим галочку в чекбоксе
              checkbox.prop("checked", true);
            }

            var checkbox = $('#parking');
            if(checkbox.prop("checked")){
              $('#edit-field-parking-value option[value=All]').attr('selected', false);
              $('#edit-field-parking-value option[value=1]').attr('selected', 'selected');
            }else {
              $('#edit-field-parking-value option[value=1]').attr('selected', false);
              $('#edit-field-parking-value option[value=All]').attr('selected', 'selected');

            }
            $('#edit-submit-apartments').trigger('click');
          });
        });
      }

      var realtyInitForm = function () {
        var i,
          wall,
          coastMin,
          coastMax,
          priceMin,
          priceMax;


/*        $('.decor_checkbox').each(function(){
          var checkbox = $('#parking');
          if(checkbox.prop("checked")) $(this).addClass("check_active_result");
        });*/

        $('#wall_type')
          .change(function(){
            wall = $(this).val();
            $('#edit-field-masonry-value option:selected').each(function(){
              this.selected=false;
            });
            for (i in wall) {
              $('#edit-field-masonry-value option[value="'+wall[i]+'"]').attr('selected', 'selected');
            }
          })
          .multipleSelect({
            placeholder: '',
            selectAllText: 'Отметить все',
            allSelected: 'Все'
          });

        $('#cat')
          .change(function(){
            wall = $(this).val();
            $('#edit-field-category-value option:selected').each(function(){
              this.selected=false;
            });
            for (i in wall) {
              $('#edit-field-category-value option[value="'+wall[i]+'"]').attr('selected', 'selected');
            }
          })
          .multipleSelect({
            placeholder: '',
            selectAllText: 'Отметить все',
            allSelected: 'Все'
          });

        $('#date')
          .change(function(){
            wall = $(this).val();
            $('#edit-field-home-deadline-quarter-value option:selected').each(function(){
              this.selected = false;
            });
            for (i in wall) {
              $('#edit-field-home-deadline-quarter-value option[value="'+wall[i]+'"]').attr('selected', 'selected');
            }
          })
          .multipleSelect({
            placeholder: '',
            selectAllText: 'Отметить все',
            allSelected: 'Все'
          });

        $('#balcon').click(function() {
          if ($(this).prop("checked") == false) {
            $('#edit-field-balcony-value option[value="1"]').attr('selected', 'selected');
            $('#edit-field-balcony-value option[value="All"]').attr('selected', false);
            $('.search-input-balcon').val('Балкон');
            if ($('#edit-field-balcony-value').val() == '1' && $('#edit-field-loggia-value').val() == '1') {
              $('.search-input-balcon').val('Лоджия, Балкон');
            }
            if($('#edit-field-balcony-value').val() == '1' && $('#edit-field-balcony-loggia-value').val() == '1') {
              $('.search-input-balcon').val('Балкон, Балкон+Лоджия');
            }
            if ($('#edit-field-balcony-value').val() == '1' && $('#edit-field-loggia-value').val() == '1' && $('#edit-field-balcony-loggia-value').val() == '1') {
              $('.search-input-balcon').val('Лоджия, Балкон, Балкон+Лоджия');
            }
          }
          else {

            $('#edit-field-balcony-value option[value="1"]').attr('selected', false);
            $('#edit-field-balcony-value option[value="All"]').attr('selected', 'selected');
            if ($('#edit-field-loggia-value').val() == '1') {
              $('.search-input-balcon').val('Лоджия');
            }
            if ($('#edit-field-balcony-loggia-value').val() == '1'){
              $('.search-input-balcon').val('Балкон+Лоджия');
            }

            if ($('#edit-field-balcony-loggia-value').val() == '1' && $('#edit-field-loggia-value').val() == '1') {
              $('.search-input-balcon').val('Лоджия, Балкон+Лоджия');
            }
            if($('#edit-field-balcony-loggia-value').val() != '1' && $('#edit-field-loggia-value').val() != '1' && $('#edit-field-balcony-value').val() != '1') {
              $('.search-input-balcon').val('');
            }
          }
        });

        $('#id-loggia').click(function() {
          if ($(this).prop("checked") == false) {
            $('#edit-field-loggia-value option[value="1"]').attr('selected', 'selected');
            $('#edit-field-loggia-value option[value="All"]').attr('selected', false);
            $('.search-input-balcon').val('Лоджия');
            if ($('#edit-field-balcony-value').val() == '1' && $('#edit-field-loggia-value').val() == '1') {
              $('.search-input-balcon').val('Балкон, Лоджия');
            }
            if ($('#edit-field-loggia-value').val() == '1' && $('#edit-field-balcony-loggia-value').val() == '1') {
              $('.search-input-balcon').val('Лоджия, Балкон+Лоджия');
            }
            if ($('#edit-field-balcony-value').val() == '1' && $('#edit-field-loggia-value').val() == '1' && $('#edit-field-balcony-loggia-value').val() == '1') {
              $('.search-input-balcon').val('Лоджия, Балкон, Балкон+Лоджия');
            }
          }
          else {
            $('#edit-field-loggia-value option[value="1"]').attr('selected', false);
            $('#edit-field-loggia-value option[value="All"]').attr('selected', 'selected');
            if ($('#edit-field-balcony-value').val() == '1' && $('#edit-field-balcony-loggia-value').val() != '1') {
              $('.search-input-balcon').val('Балкон');
            }
            if ($('#edit-field-balcony-loggia-value').val() == '1' && $('#edit-field-balcony-value').val() != '1'){
              $('.search-input-balcon').val('Балкон+Лоджия');
            }
            if ($('#edit-field-balcony-loggia-value').val() == '1' && $('#edit-field-balcony-value').val() == '1') {
              $('.search-input-balcon').val('Балкон, Балкон+Лоджия');
            }
            if($('#edit-field-balcony-loggia-value').val() != '1' && $('#edit-field-loggia-value').val() != '1' && $('#edit-field-balcony-value').val() != '1') {
              $('.search-input-balcon').val('');
            }
          }
        });

        $('#id-loggia-balcon').click(function() {
          console.log('okok');
          if ($(this).prop("checked") == false) {
            $('#edit-field-balcony-loggia-value option[value="1"]').attr('selected', 'selected');
            $('#edit-field-balcony-loggia-value option[value="All"]').attr('selected', false);
            $('.search-input-balcon').val('Балкон+Лоджия');
            if ($('#edit-field-balcony-value').val() == '1') {
              $('.search-input-balcon').val('Балкон, Балкон+Лоджия');
            }
            if ($('#edit-field-loggia-value').val() == '1') {
              $('.search-input-balcon').val('Лоджия, Балкон+Лоджия');
            }
            if ($('#edit-field-balcony-value').val() == '1' && $('#edit-field-loggia-value').val() == '1') {
              $('.search-input-balcon').val('Балкон, Лоджия, Балкон+Лоджия');
            }
          }
          else {
            $('#edit-field-balcony-loggia-value option[value="1"]').attr('selected', false);
            $('#edit-field-balcony-loggia-value option[value="All"]').attr('selected', 'selected');
            if ($('#edit-field-balcony-value').val() == '1') {
              $('.search-input-balcon').val('Балкон');
            }
            if ($('#edit-field-loggia-value').val() == '1'){
              $('.search-input-balcon').val('Лоджия');
            }
            if ($('#edit-field-balcony-value').val() == '1' && $('#edit-field-loggia-value').val() == '1') {
              $('.search-input-balcon').val('Балкон, Лоджия');
            }
            if($('#edit-field-balcony-loggia-value').val() != '1' && $('#edit-field-loggia-value').val() != '1' && $('#edit-field-balcony-value').val() != '1') {
              $('.search-input-balcon').val('');
            }
          }
        });

        $('#edit-year').change(function(){
          $('#' +
            'ne-year-value').val($(this).val());
        });

        $(".floor").change(function(){

          wall = $(this).val();
          wall = wall.split(';');
          $('#edit-field-apartment-floor-value-min').val(wall[0]);
          $('#edit-field-apartment-floor-value-max').val(wall[1]);

          string_input = new String(wall[0])+' - '+new String(wall[1]);
          $(".search-input-floor").val(string_input);

          $('#modal_floor-from_value').html(wall[0]+'<span>до</span>');
          $('#modal_floor-to_value').html(wall[1]);
        });

        $(".sq").change(function(){
          wall = $(this).val();
          wall = wall.split(';');
          $('#edit-field-gross-area-value-min').val(wall[0]);
          $('#edit-field-gross-area-value-max').val(wall[1]);

          string_input = new String(wall[0])+' - '+new String(wall[1])+' кв. м.';
          $(".search-input-sq").val(string_input);

          $('#modal_slider_sq-from_value').html(wall[0]+'<span>до</span>');
          $('#modal_slider_sq-to_value').html(wall[1]);
        });

        $(".price").change(function(){
          wall = $(this).val();
          wall = wall.split(';');
          console.log(1);
          priceMin = wall[0] * 1000;
          wall[1] == 100 ? priceMax = wall[1] * 100000 :  priceMax = wall[1] * 1000;

          $('#edit-field-price-value-min').val(priceMin);
          $('#edit-field-price-value-max').val(priceMax);

          string_input = new String(priceMin / 1000)+' - '+new String(priceMax / 1000)+' тыс. руб.';
          $(".search-input-price").val(string_input);

          $('#modal_slider_price-from_value').html(priceMin/1000+'<span>до</span>');
          $('#modal_slider_price-to_value').html(priceMax/1000);
        });

        $(".coast").change(function(){
          wall = $(this).val();
          wall = wall.split(';');
          coastMin = wall[0] * 1000000;
          wall[1] == 5 ? coastMax = wall[1] * 100000000 :  coastMax = wall[1] * 1000000;
          console.log(coastMin);
          $('#edit-field-full-cost-value-min').val(coastMin);
          $('#edit-field-full-cost-value-max').val(coastMax);

          string_input = new String(coastMin/1000000)+' - '+new String(coastMax/1000000)+' млн. руб.';
          $(".search-input-cost").val(string_input);

          $('#modal_slider_cost-from_value').html(coastMin/1000000+'<span>до</span>');
          $('#modal_slider_cost-to_value').html(coastMax/1000000);
        });

        $(".ceiling").change(function(){
          wall = $(this).val();
          wall = wall.split(';');
          $('#edit-field-apartment-ceiling-height-value-min').val(wall[0]);
          $('#edit-field-apartment-ceiling-height-value-max').val(wall[1]);

          string_input = new String(wall[0])+' - '+new String(wall[1])+' м';
          $(".search-input-ceiling").val(string_input);

          $('#modal_slider_ceiling-from_value').html(wall[0]+'<span>до</span>');
          $('#modal_slider_ceiling-to_value').html(wall[1]);
        });

        $('#edit-submit').click(function(){
          $('#edit-submit-apartments').trigger('click');
        })

        $('.search-button').click(function(){
          $('#edit-submit-apartments').trigger('click');
          $('div.realty-preload').show();
        })

        $(document).ajaxComplete(function(e, xhr, settings) {

          if (settings.url == Drupal.settings.basePath + "?q=views/ajax" || settings.url == Drupal.settings.basePath + "views/ajax" || settings.url == Drupal.settings.basePath + "?q=system/ajax" ||  settings.url == Drupal.settings.basePath + "system/ajax") {
            // enable selectBox jQuery plugin for all <select> elements
            $('div.realty-preload').fadeOut('0',function() {
              //$(this).remove();
            });
            //Drupal.attachbehaviours();

          }
        });

      }

      var realtyInitValueForm = function () {
        var i,
          n,
          areas = $('#edit-field-area-tid').val(),
          developers = $('#edit-field-complex-developer-tid').val(),
          deadline = $('#edit-field-deadline-value').val(),
          complexes = $('#edit-field-home-complex-target-id').val(),
          rooms = $('#edit-field-number-rooms-value').val(),
          floorMin = $('#edit-field-apartment-floor-value-min').val(),
          floorMax = $('#edit-field-apartment-floor-value-max').val(),
          material = $('#edit-field-material-tid').val(),
          category = $('#edit-field-home-category-tid').val(),
          quarter = $('#edit-field-home-deadline-quarter-value').val(),
          loggia = $('#edit-field-loggia-value').val(),
          balcony = $('#edit-field-balcony-value').val(),
          balcony_loggia = $('#edit-field-balcony-loggia-value').val(),
          year = $('#edit-field-home-deadline-year-value').val(),
          sqMin = $('#edit-field-gross-area-value-min').val(),
          sqMax = $('#edit-field-gross-area-value-max').val(),
          priceMin = $('#edit-field-price-value-min').val() / 1000,
          priceMax = $('#edit-field-price-value-max').val() / 1000,
          coastMin = $('#edit-field-full-cost-value-min').val() / 1000000,
          coastMax = $('#edit-field-full-cost-value-max').val() / 1000000,
          ceilingMin = $('#edit-field-apartment-ceiling-height-value-min').val(),
          ceilingMax = $('#edit-field-apartment-ceiling-height-value-max').val(),
          parking = $('#edit-field-parking-value').val(),
          metro = $('#edit-field-complex-metro-tid').val();

        console.log(sqMax); console.log(priceMax); console.log(coastMax);

        sqMax == '110000' ? sqMax = 200 : sqMax;
        priceMax == 125000 ? priceMax = 100 : priceMax;
        coastMax == 45000 ? coastMax = 5 : coastMax;

        console.log(sqMax); console.log(priceMax); console.log(coastMax);
        // Значения по умолчанию для Слайдеров
        var
          floorMinDefault = 0,
          floorMaxDefault = 30,

          sqMinDefault = 0,
          sqMaxDefault = 200,

          priceMinDefault = 0,
          priceMaxDefault = 100,

          coastMinDefault = 0,
          coastMaxDefault = 5,

          ceilingMinDefault = 0,
          ceilingMaxDefault = 5;

        //Заполняем модальное окно и кнопку фильтра площадь
        $(".sq").ionRangeSlider({
          hide_min_max: true,
          keyboard: true,
          min: 0,
          max: 200,
          from: sqMin != 0 ? sqMin : sqMinDefault,
          to: sqMax != 0 ? sqMax: sqMaxDefault,
          type: 'double',
          step: 1,
          grid: true,
          max_postfix: "+"
        });
        var sqMinCur = sqMin =! 0 ? sqMin : sqMinDefault;
        var sqMaxCur = sqMax =! 0 ? sqMax : sqMaxDefault;
        var sqMaxPostfix = sqMax == sqMaxDefault ? '+ кв. м' : ' кв. м';

        $('.search-input-sq').val(sqMinCur+' - '+sqMaxCur+sqMaxPostfix);
        $('#modal_slider_sq-from_value').html(sqMin+'<span>до</span>');
        $('#modal_slider_sq-to_value').html(sqMax);

        //Заполняем модальное окно и кнопку фильтра цена за кв. м.
        $(".price").ionRangeSlider({
          hide_min_max: true,
          keyboard: true,
          min: 0,
          max: 100,
          from: priceMin != 0 ? priceMin : priceMinDefault,
          to: priceMax != 0 ? priceMax : priceMaxDefault,
          type: 'double',
          step: 1,
          grid: true,
          hasGrid: true,
          max_postfix: "+"
        });
        var priceMinCur = priceMin =! 0 ? priceMin : priceMinDefault;
        var priceMaxCur = priceMax =! 0 ? priceMax : priceMaxDefault;
        var priceMaxPostfix = priceMax == priceMaxDefault ? '+ тыс. руб.' : ' тыс. руб.';

        $('.search-input-price').val(priceMinCur+' - '+priceMaxCur+priceMaxPostfix);
        $('#modal_slider_price-from_value').html(priceMin+'<span>до</span>');
        $('#modal_slider_price-to_value').html(priceMax);

        //Заполняем модальное окно и кнопку фильтра стоимость
        $(".coast").ionRangeSlider({
          hide_min_max: true,
          keyboard: true,
          min: 0,
          max: 5,
          from: coastMin != 0 ? coastMin : coastMinDefault,
          to: coastMax != 0 ? coastMax : coastMaxDefault,
          type: 'double',
          step: 0.2,
          grid: true,
          hasGrid: true,
          max_postfix: "+"
        });
        var coastMinCur = coastMin =! 0 ? coastMin : coastMinDefault;
        var coastMaxCur = coastMax =! 0 ? coastMax : coastMaxDefault;
        var coastMaxPostfix = coastMax == coastMaxDefault ? '+ млн. руб.' : ' млн. руб.';

        $('.search-input-cost').val(coastMinCur+' - '+coastMaxCur+coastMaxPostfix);
        $('#modal_slider_cost-from_value').html(coastMin+'<span>до</span>');
        $('#modal_slider_cost-to_value').html(coastMax);

        // Заполняем модальное окно и кнопку фильтра высота потолка
        $(".ceiling").ionRangeSlider({
          hide_min_max: true,
          keyboard: true,
          min: 0,
          max: 5,
          from: ceilingMin  != 0 ? ceilingMin : ceilingMinDefault,
          to: ceilingMax != 0 ? ceilingMax : ceilingMaxDefault,
          type: 'double',
          step: 0.1,
          grid: true,
          hasGrid: true,
          max_postfix: "+"
        });
        var ceilingMinCur = ceilingMin =! 0 ? ceilingMin : ceilingMinDefault;
        var ceilingMaxCur = ceilingMax =! 0 ? ceilingMax : ceilingMaxDefault;
        var ceilingMaxPostfix = ceilingMax == ceilingMaxDefault ? '+ м' : ' м';

        $('.search-input-ceiling').val(ceilingMinCur+' - '+ceilingMaxCur+ceilingMaxPostfix);
        $('#modal_slider_ceiling-from_value').html(ceilingMin+'<span>до</span>');
        $('#modal_slider_ceiling-to_value').html(ceilingMax);

        //Заполняем модальное окно и кнопку фильтра этаж
        $(".floor").ionRangeSlider({
          hide_min_max: true,
          keyboard: true,
          min: 1,
          max: 30,
          from: floorMin != 0 ? floorMin : floorMinDefault,
          to: floorMax != 0 ? floorMax : floorMaxDefault,
          type: 'double',
          step: 1,
          grid: true,
          hasGrid: true,
          max_postfix: "+"
        });
        var floorMinCur = floorMin =! 0 ? floorMin : floorMinDefault;
        var floorMaxCur = floorMax =! 0 ? floorMax : floorMaxDefault;
        var floorMaxPostfix = floorMax == floorMaxDefault ? '+' : '';

        $('.search-input-floor').val(floorMinCur+' - '+floorMaxCur+floorMaxPostfix);
        $('#modal_floor-from_value').html(floorMin+'<span>до</span>');
        $('#modal_floor-to_value').html(floorMax);

        //Заполняем модальное окно и кнопку фильтра срок сдачи
        for (i in deadline) {
          $('#id-modal_deadline-' + deadline[i]).trigger('click');
        }

        //Заполняем модальное окно и кнопку фильтра застройщики
        for (i in developers) {
          $('#id-modal_developer-' + developers[i]).trigger('click');
        }


        //Заполняем модальное окно и кнопку фильтра районы
        for (i in areas) {
          $('#id-modal_area-'+areas[i]).trigger('click');
        }


        //Заполняем модальное окно и кнопку фильтра жилые комплексы
        for (i in complexes) {
          $('#id-modal_complex-'+complexes[i]).trigger('click');
        }

        //Заполняем модальное окно и кнопку фильтра комнаты
        for (i in rooms) {
          $('#id-modal_type-'+rooms[i]).trigger('click');
        }

        //Заполняем модальное окно и кнопку фильтра материал стен
        for (i in material) {

          $('#id-modal_material-'+material[i]).trigger('click');
        }

        //Заполняем модальное окно и кнопку фильтра категория
        for (i in category) {
          $('#id-modal_category-'+category[i]).trigger('click');
        }

        //Заполняем модальное окно и кнопку фильтра метро
        for (i in metro) {
          $('#id-modal_metro-'+metro[i]).trigger('click');
        }

        //Заполняем модальное окно и кнопку фильтра балкон и лоджия
        console.log('балкон:'+balcony);
        console.log('лоджия:'+loggia);
        console.log('балкон+лоджия:'+balcony_loggia);
        if (loggia == 1 && balcony == 1 && balcony_loggia == 1) {
          console.log('балкон, лоджия, балкон+лоджия');
          $('#id-loggia').trigger('click');
          $('#balcon').trigger('click');
          $('#id-loggia-balcon').trigger('click');
          $('.search-input-balcon').val('балкон, лоджия, балкон+лоджия');
          $('#edit-field-loggia-value option[value="1"]').attr('selected', 'selected');
          $('#edit-field-balcony-value option[value="1"]').attr('selected', 'selected');
          $('#edit-field-balcony-loggia-value option[value="1"]').attr('selected', 'selected');
        }
        if (loggia == 1 && balcony == 1 && balcony_loggia != 1) {
          console.log('балкон, лоджия');
          $('#id-loggia').trigger('click');
          $('#balcon').trigger('click');
          $('.search-input-balcon').val('балкон, лоджия');
          $('#edit-field-loggia-value option[value="1"]').attr('selected', 'selected');
          $('#edit-field-balcony-value option[value="1"]').attr('selected', 'selected');
        }
        if (loggia == 1 && balcony != 1 && balcony_loggia == 1) {
          console.log('лоджия, балкон+лоджия');
          $('#id-loggia').trigger('click');
          $('#id-loggia-balcon').trigger('click');
          $('.search-input-balcon').val('лоджия, балкон+лоджия');
          $('#edit-field-loggia-value option[value="1"]').attr('selected', 'selected');
          $('#edit-field-balcony-loggia-value option[value="1"]').attr('selected', 'selected');
        }
        if (loggia != 1 && balcony == 1 && balcony_loggia == 1) {
          console.log('балкон, балкон+лоджия');
          $('#balcon').trigger('click');
          $('#id-loggia-balcon').trigger('click');
          $('.search-input-balcon').val('балкон, балкон+лоджия');
          $('#edit-field-balcony-value option[value="1"]').attr('selected', 'selected');
          $('#edit-field-balcony-loggia-value option[value="1"]').attr('selected', 'selected');
        }

        if (loggia != 1 && balcony != 1 && balcony_loggia == 1) {
          console.log('балкон+лоджия');
          $('#id-loggia-balcon').trigger('click');
          $('.search-input-balcon').val('балкон+лоджия');
          $('#edit-field-balcony-loggia-value option[value="1"]').attr('selected', 'selected');
        }
        if (loggia == 1 && balcony != 1 && balcony_loggia != 1) {
          console.log('лоджия');
          $('#id-loggia').trigger('click');
          $('.search-input-balcon').val('лоджия');
          $('#edit-field-loggia-value option[value="1"]').attr('selected', 'selected');
        }
        if (loggia != 1 && balcony == 1 && balcony_loggia != 1) {
          console.log('балкон');
          $('#balcon').trigger('click');
          $('.search-input-balcon').val('балкон');
          $('#edit-field-balcony-value option[value="1"]').attr('selected', 'selected');
        }


        /*
         for (i in quarter) {
         n = quarter[i]-1;
         $('input[name="selectItemquarter[]"]:eq('+n+')').trigger('click');
         }

         $('#edit-year').val(year);
         //$('#floor').val(floor);

         */
        if (parking == 1) {
          $('#parking').trigger('click');
        }

        currentSelection = [];
      };

      var complex_select = function(devid) {
        var city = $('input[name="city"]').val();
        console.log(city);
        $.ajax({
          url: '/get_developer_complex',
          type: 'POST',
          data: {
            developer: devid,
            city: 1
          },
          success: function(response) {
            var object = jQuery.parseJSON(response);
            console.log(response);
            $('.complexes-lis').html('');
            $('#complex').html('');
            if (object != null) {
              $('.complexes-lis').html(object.modal);
              $('#edit-field-home-complex-target-id').html(object.select);
            }
          },
          error: function(response) {
            alert('false');
          }
        });
      }

      devid={};

      var currentSelection = [];

      var multiselect_modal = function(class_check_box, id_select, class_input) {
        var array_input = {};
        var string_input = '';
        $(document).on('click', '.'+class_check_box, function(){

          var param =  $(this).val().split(';');

          // @todo Костыль
          // Нужно разобраться почему на этапе загрузке свойство checkbox'a возвращает true,
          // а в процессе работы false
          if ($(this).prop("checked") == loading ) {
            console.log("true");


            $('#'+id_select+' option[value='+param[0]+']').attr('selected', 'selected');
            $('#'+id_select+' option[value='+param[0]+']').prop('selected', true);

            array_input[param[1]] = param[1];

            if (class_check_box == 'CheckboxDeveloper') {
              devid[param[0]] = param[0];
              $('.search-input-complex').val('');
              console.log(devid);
              complex_select(devid);
            }

            string_input = '';
            $.each(array_input, function(key, val) {
              string_input == '' ?  string_input = val : string_input += ', '+val;
            });
            $('.'+class_input).val(string_input);

            currentSelection.push({
              'class': class_check_box,
              'value': $(this).val()
            });

            if(currentSelection[0]) {
              var classCheck = currentSelection[0];
              if(classCheck.class != class_check_box) {
                currentSelection = [];
                currentSelection.push({
                  'class': class_check_box,
                  'value': $(this).val()
                });
              }
            }

          }

          else {
            console.log("false");



            $('#' + id_select + ' option[value=' + param[0] + ']').attr('selected', false);

            delete array_input[param[1]];
            string_input = '';
            $.each(array_input, function (key, val) {
              string_input == '' ? string_input = val : string_input += ', ' + val;
            });
            $('.' + class_input).val(string_input);

            if (class_check_box == 'CheckboxDeveloper') {
              delete devid[param[0]];
              $('.search-input-complex').val('');
              complex_select(devid);
            }
          }
        });
      }
      loading = true;

      realtyInitForm();

      multiselect_modal('CheckboxDeadline', 'edit-field-deadline-value', 'search-input-deadline');
      multiselect_modal('CheckboxArea', 'edit-field-area-tid', 'search-input-area');
      multiselect_modal('CheckboxRoom', 'edit-field-number-rooms-value', 'search-input-room');
      multiselect_modal('CheckboxDeveloper', 'edit-field-complex-developer-tid', 'search-input-developer');
      multiselect_modal('CheckboxMetro', 'edit-field-complex-metro-tid', 'search-input-metro');
      multiselect_modal('CheckboxComplex', 'edit-field-home-complex-target-id', 'search-input-complex');
      multiselect_modal('CheckboxMaterial', 'edit-field-material-tid', 'search-input-masonry');
      multiselect_modal('CheckboxCategory', 'edit-field-home-category-tid', 'search-input-category');

      realtyInitValueForm();
      apartmentStatus();
      realtyParkingFilter();

      loading = false;


      $(".modal").on('hidden.bs.modal', function(){
        currentSelection = [];
        $('#edit-submit-apartments').trigger('click');
      });


      $('.close-modal').click(function(){
        var closeClass = $(this).data('class');
        if(currentSelection[0]) {
          var classCheck = currentSelection[0];
          if(classCheck.class == closeClass) {
            var classes = $('.'+closeClass);
            for(var i = 0; i < classes.length; i++) {
              for(var j in currentSelection) {
                var tekVal = $(currentSelection[j])[0].value;
                if(tekVal == $(classes[i]).val()) {
                  $('label[for='+$(classes[i]).attr('id')+']').trigger('click');
                  $(classes[i]).prop('checked', false);
                  $(classes[i]).trigger('click');
                }
              }
            }
          }

        }
      });


    })
  };

  Drupal.behaviors.realtyResetForm = {
    attach: $(function() {

      // Обработка нажатия кнопки Сбросить фильтры
      $(document).on('click', '#realty-filter-reset', function () {

        var i,
          areas = $('#edit-field-area-tid').val(),
          developers = $('#edit-field-complex-developer-tid').val(),
          deadline = $('#edit-field-deadline-value').val(),
          complexes = $('#edit-field-home-complex-target-id').val(),
          type = $('#edit-field-number-rooms-value').val(),
          material = $('#edit-field-material-tid').val(),
          category = $('#edit-field-home-category-tid').val(),
          quarter = $('#edit-field-home-deadline-quarter-value').val(),
          loggia = $('#edit-field-loggia-value').val(),
          balcony = $('#edit-field-balcony-value').val(),
          balcony_loggia = $('#edit-field-balcony-loggia-value').val(),
          year = $('#edit-field-home-deadline-year-value').val(),
          parking = $('#edit-field-parking-value').val(),
          metro = $('#edit-field-complex-metro-tid').val();


        for (i in category) {
          //@todo Баг. При клике на input не меняется статус checkbox'a
          $('#id-modal_category-' + category[i]).prop('checked', false);
          $('.modal_category-' + category[i]).trigger('click');
        }

        for (i in areas) {
          //@todo Баг. При клике на input не меняется статус checkbox'a
          $('#id-modal_area-' + areas[i]).prop('checked', false);
          $('.modal_area-' + areas[i]).trigger('click');
        }

        for (i in developers) {
          //@todo Баг. При клике на input не меняется статус checkbox'a
          $('#id-modal_developer-' + developers[i]).prop('checked', false);
          $('.modal_developer-' + developers[i]).trigger('click');
        }

        for (i in deadline) {
          //@todo Баг. При клике на input не меняется статус checkbox'a
          $('#id-modal_deadline-' + deadline[i]).prop('checked', false);
          $('.modal_deadline-' + deadline[i]).trigger('click');
        }

        for (i in complexes) {
          //@todo Баг. При клике на input не меняется статус checkbox'a
          $('#id-modal_complex-' + complexes[i]).prop('checked', false);
          $('.modal_complex-' + complexes[i]).trigger('click');
        }

        for (i in type) {
          //@todo Баг. При клике на input не меняется статус checkbox'a
          $('#id-modal_type-' + type[i]).prop('checked', false);
          $('.modal_type-' + type[i]).trigger('click');
        }

        for (i in material) {
          //@todo Баг. При клике на input не меняется статус checkbox'a
          $('#id-modal_material-' + material[i]).prop('checked', false);
          $('.modal_material-' + material[i]).trigger('click');
        }

        if (balcony) {
          //@todo Баг. При клике на input не меняется статус checkbox'a
          $('#balcon').prop('checked', false);
          $('.CheckboxBalcony').trigger('click');
        }

        if (loggia) {
          //@todo Баг. При клике на input не меняется статус checkbox'a
          $('#id-loggia').prop('checked', false);
          $('.CheckboxLoggia').trigger('click');
        }

        if (balcony_loggia) {
          //@todo Баг. При клике на input не меняется статус checkbox'a
          $('#id-loggia-balcon').prop('checked', false);
          $('.CheckboxLoggia').trigger('click');
        }

        for (i in metro) {
          //@todo Баг. При клике на input не меняется статус checkbox'a
          $('#id-modal_metro-' + metro[i]).prop('checked', false);
          $('.modal_metro-' + metro[i]).trigger('click');
        }

        var slider = $(".floor").data("ionRangeSlider");

        slider.update({
          min: 1,
          max: 30,
          from:1,
          to: 30,
          step: 1
        });
        $('#edit-field-apartment-floor-value-min').val(1);
        $('#edit-field-apartment-floor-value-max').val(30);
        $(".search-input-floor").val('1 - 30+');

        var slider = $(".sq").data("ionRangeSlider");
        slider.update({
          min: 0,
          max: 200,
          from: 0,
          to: 200,
          step: 1
        });
        $('#edit-field-gross-area-value-min').val(0);
        $('#edit-field-gross-area-value-max').val(200);
        $(".search-input-sq").val('0 - 200+ кв. м.');

        var slider = $(".price").data("ionRangeSlider");
        slider.update({
          min: 0,
          max: 100,
          from: 0,
          to: 100,
          step: 1
        });
        $('#edit-field-price-value-min').val(0);
        $('#edit-field-price-value-max').val(100000);
        $(".search-input-price").val('0 - 100+ т. р.');

        var slider = $(".coast").data("ionRangeSlider");

        slider.update({
          min: 0,
          max: 5,
          from: 0,
          to: 5,
          step: 0.2
        });
        $('#edit-field-full-cost-value-min').val(0);
        $('#edit-field-full-cost-value-max').val(5000000);
        $(".search-input-cost").val('0 - 5+ млн. р.');

        var slider = $(".ceiling").data("ionRangeSlider");

        slider.update({
          min: 0,
          max: 5,
          from: 0,
          to: 5,
          step: 0.2
        });
        $('#edit-field-apartment-ceiling-height-value-min').val(0);
        $('#edit-field-apartment-ceiling-height-value-max').val(5);
        $(".search-input-ceiling").val('0 - 5+ м.');

        if ($('#booking-c').prop("checked") == true) {
          $('#booking-check').trigger('click');
        }

        if ($('#parking').prop("checked") == true) {
          $('#parking-check').trigger('click');
        }


        $('#edit-submit-apartments').trigger('click');

      })
    })
  };

}(jQuery));