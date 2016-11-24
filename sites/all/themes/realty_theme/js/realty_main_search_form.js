(function ($) {

  Drupal.behaviors.realtyFormSearch = {
    attach: $(function() {


      $(".modal").on('hidden.bs.modal', function(){
        currentSelection = [];
        queryCountResult();
      });

      var multiple_select_form = function() {

        $('.span-checkbox-area').click(function(){
          var classCheckbox,
            id = $(this).attr('id');
          var idLeng = id.length;
          var id = id.slice(6, idLeng);
          console.log(id);
          //$($(this).attr('id')+'  CheckboxArea').trigger('click');
        });

//  section type multiple select
        $(function() {
          $(".floor").change(function(){

            wall = $(this).val();
            wall = wall.split(';');
            $('#edit-field-apartment-floor-value-min').val(wall[0]);
            $('#edit-field-apartment-floor-value-max').val(wall[1]);

            string_input = new String(wall[0])+' - '+new String(wall[1]);
            $(".search-main-input-floor").val(string_input);
          });
        });

//  balkon type multiple select
        $(function() {
          $('#balkon').change(function() {
            console.log($(this).val());
            $('#edit-field-balcony-value [value=1]').attr('selected', false);
            $('#edit-field-loggia-value [value=1]').attr('selected', false);
            for (var i in $(this).val()) {
              console.log($(this).val()[i]);
              if ($(this).val()[i] == 0) {
                $('#edit-field-balcony-value [value=1]').attr('selected', 'selected');
              }
              if ($(this).val()[i] == 1)  {
                $('#edit-field-loggia-value [value=1]').attr('selected', 'selected');
              }
            }
          }).multipleSelect({
            placeholder: '',
            selectAllText: 'Отметить все',
            allSelected: 'Все'
          });
        });

      };

      multiple_select_form();
      $(document).ajaxSuccess(function() {
        multiple_select_form();
      });

      timerId = null;
      queryCountResult = function () {
        $.ajax({
          url: '/search_count_result',
          type: 'POST',
          data: {
            sq_min: $('#textfield_sq_min').val(),
            sq_max: $('#textfield_sq_max').val(),
            price_min: $('#textfield_price_min').val(),
            price_max: $('#textfield_price_max').val(),
            cost_min: $('#textfield_cost_min').val(),
            cost_max: $('#textfield_cost_max').val(),
            floors_min: $('#textfield_floor_min').val(),
            floors_max: $('#textfield_floor_max').val(),
            areas:  $('#select_area').val(),
            developers: $('#select_developer').val(),
            deadline: $('#select_deadline').val(),
            complexes: $('#select_complex').val(),
            type: $('#select_type').val(),
            material: $('#select_material').val(),
            category: $('#select_category').val(),
            balcony: $('#select_balkon').val(),
            metro: $('#select_metro').val(),
            city: $('#city_id').data('city-id')
          },
          success: function(response) {
            $('#count_result').html(response);
            timerId = null;
          },
          error: function(response) {
            alert('false');
          }
        });
      };

      // Значения по умолчанию для Слайдеров
      var
        floorMinDefault = 1,
        floorMaxDefault = 30,
        floorMinCur = 1,
        floorMaxCur = 30,

        sqMinDefault = 15,
        sqMaxDefault = 110,
        sqMinCur = 15,
        sqMaxCur = 95,

        priceMinDefault = 30,
        priceMaxDefault = 125,
        priceMinCur = 35,
        priceMaxCur = 100,

        coastMinDefault = 0.5,
        coastMaxDefault = 4.5,
        coastMinCur = 0.9,
        coastMaxCur = 4.5;

      // Площадь
      $(".sq").ionRangeSlider({
        hide_min_max: true,
        keyboard: true,
        min: sqMinDefault,
        max: sqMaxDefault,
        from: sqMinCur,
        to: sqMaxCur,
        min_interval: 10,
        type: 'double',
        step: 1,
        grid: true,
        max_postfix: "+",
        onChange: function (data) {
          if (timerId == null) {
            timerId = setTimeout(function () {
              queryCountResult()
            }, 500);
          }
          else {
            clearTimeout(timerId);
            timerId = setTimeout(function () {
                queryCountResult()
              }, 500
            );
          }
        }
      });
      $('#textfield_sq_min').val(sqMinCur);
      $('#textfield_sq_max').val(sqMaxCur);

      $(".sq").change(function(){
        var sq =  $(this).val().split(';'), sqMax;

        sq[1] == 110 ? sqMax = sq[1] * 1000 :  sqMax = sq[1];
        $('#textfield_sq_min').val(sq[0]);
        $('#textfield_sq_max').val(sqMax);

        $('#current-sq').html('от <span>'+sq[0]+'</span> до <span>'+sq[1]+' </span>м<sup>2</sup>');
      });

      // Цена
      $(".price").ionRangeSlider({
        hide_min_max: true,
        keyboard: true,
        min: priceMinDefault,
        max: priceMaxDefault,
        from: priceMinCur,
        to: priceMaxCur,
        min_interval: 10,
        type: 'double',
        step: 1,
        grid: true,
        hasGrid: true,
        max_postfix: "+",
        onChange: function (data) {
          if (timerId == null) {
            timerId = setTimeout(function () {
              queryCountResult()
            }, 500);
          }
          else {
            clearTimeout(timerId);
            timerId = setTimeout(function () {
                queryCountResult()
              }, 500
            );
          }
        }
      });
      $('#textfield_price_min').val(priceMinCur * 1000);
      $('#textfield_price_max').val(priceMaxCur * 1000);

      $(".price").change(function(){
        var price =  $(this).val().split(';'),
          priceMin = price[0]*1000,
          priceMax, r_price;
        price[1] == 125 ? priceMax = price[1] * 1000000 :  priceMax = price[1] * 1000;

        $('#textfield_price_min').val(priceMin);
        $('#textfield_price_max').val(priceMax);

        $('#current-price').html('от <span>'+price[0]+'</span> до <span>'+price[1]+'</span> тыс.р. за м<sup>2</sup>');
      });

      // Стоимость
      $(".coast").ionRangeSlider({
        hide_min_max: true,
        keyboard: true,
        min: coastMinDefault,
        max: coastMaxDefault,
        from: coastMinCur,
        to: coastMaxCur,
        min_interval: 0.5,
        type: 'double',
        step: 0.1,
        grid: true,
        hasGrid: true,
        max_postfix: "+",
        onChange: function (data) {
          if (timerId == null) {
            timerId = setTimeout(function () {
              queryCountResult()
            }, 500);
          }
          else {
            clearTimeout(timerId);
            timerId = setTimeout(function () {
                queryCountResult()
              }, 500
            );
          }
        }
      });
      $('#textfield_cost_min').val(coastMinCur * 1000000);
      $('#textfield_cost_max').val(coastMaxCur * 1000000);

      $(".coast").change(function(){
        var coast =  $(this).val().split(';'),
          coastMin = coast[0] * 1000000,
          coastMax;
        coast[1] == 4.5 ? coastMax = coast[1] * 1000000000 : coastMax = coast[1] * 1000000;
        $('#textfield_cost_min').val(coastMin);
        $('#textfield_cost_max').val(coastMax);

        $('#current-coast').html('от <span>'+coast[0]+'</span> до <span>'+coast[1]+'</span> млн.р.');
      });

      //Этаж
      $(".floor").ionRangeSlider({
        hide_min_max: true,
        keyboard: true,
        min: floorMinDefault,
        max: floorMaxDefault,
        from: floorMinCur,
        to: floorMaxCur,
        type: 'double',
        step: 1,
        grid: true,
        hasGrid: true,
        max_postfix: "+",
        onChange: function (data) {
          if (timerId == null) {
            timerId = setTimeout(function () {
              queryCountResult()
            }, 500);
          }
          else {
            clearTimeout(timerId);
            timerId = setTimeout(function () {
                queryCountResult()
              }, 500
            );
          }
        }
      });
      $('#textfield_floor_min').val(floorMinCur);
      $('#textfield_floor_max').val(floorMaxCur);

      $('#modal_floor-from_value').html(floorMinCur+'<span>до</span>');
      $('#modal_floor-to_value').html(floorMaxCur);

      $(".floor").change(function(){

        wall = $(this).val();
        wall = wall.split(';');
        $('#textfield_floor_min').val(wall[0]);
        $('#textfield_floor_max').val(wall[1]);

        string_input = new String(wall[0])+' - '+new String(wall[1]);
        $(".search-input-floor").val(string_input);

        $('#modal_floor-from_value').html(wall[0]+'<span>до</span>');
        $('#modal_floor-to_value').html(wall[1]);
      });

      $(document).on('click', '.ok-button', function() {
        queryCountResult();
      });

      // Клик по слайдеру
      $(document).on('click', '.type_last', function(){
        if($(this).val() == 'NaN'){
          console.log($(this).val());
        }
      });

      $('#left-item').click( function () {
        $('#edit-realty-filter-submit').trigger('click');
      });

      devid = {};

      var currentSelection = [];

      var multiselect_modal = function(class_check_box, id_select, class_input) {
        var array_input = {};
        var string_input = '';

        $(document).on('click', '.'+class_check_box, function() {
          var param =  $(this).val().split(';');

          if ($(this).prop("checked") == false ) {
            $('#'+id_select+' option[value='+param[0]+']').attr('selected', 'selected');
            $('#'+id_select+' option[value='+param[0]+']').prop('selected', true);
            array_input[param[1]] = param[1];

            string_input = '';
            $.each(array_input, function(key, val) {
              string_input == '' ? string_input = val : string_input += ', '+val;
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
              //console.log(currentSelection);
            }
          }
          else {
            $('#'+id_select+' option[value='+param[0]+']').attr('selected', false);
            delete array_input[param[1]];
            string_input = '';
            $.each(array_input, function(key, val) {
              string_input == '' ?  string_input = val : string_input += ', '+val;
            });
            string_input == '' ? string_input = Drupal.t('Все') : string_input;
            $('.'+class_input).val(string_input);
          }
        });
      };

      multiselect_modal('CheckboxDeadline', 'select_deadline', 'search-main-input-deadline');
      multiselect_modal('CheckboxCategory', 'select_category', 'search-main-input-category');
      multiselect_modal('CheckboxArea', 'select_area', 'search-main-input-area');
      multiselect_modal('CheckboxRoom', 'select_type', 'search-main-input-type');
      multiselect_modal('CheckboxDeveloper', 'select_developer', 'search-main-input-developer');
      multiselect_modal('CheckboxMetro', 'select_metro', 'search-main-input-metro');
      multiselect_modal('CheckboxComplex', 'select_complex', 'search-main-input-complex');
      multiselect_modal('CheckboxMaterial', 'select_material', 'search-main-input-masonry');
      multiselect_modal('CheckboxBalkon', 'select_balkon', 'search-main-input-balcony');

      function complex_select(devid) {
        var city = Drupal.settings.city;
        $.ajax({
          url: '/get_developer_complex',
          type: 'POST',
          data: {
            developer: devid,
            city: city
          },
          success: function(response) {
            var object = jQuery.parseJSON(response);
            console.log(response);
            $('.complexes-lis').html('');
            $('#complex').html('');
            if (object != null) {
              $('.complexes-lis').html(object.modal);
              $('#complex').html(object.select);
            }
          },
          error: function(response) {
            alert('false');
          }
        });
      }

      // чек бокс для бронирования на парковки
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
        });
      });

      $(document).ready(function(){
        $(".iab").css("background","rgba(0, 183, 228, 0.5)");
        $(".search-input").hover(function(){
          $(".iab").css("background","#3f91b2");
          $(".iab h1").css("opacity","1");
          $(".iab p").css("color","#fff");
        });
        $(".search-input").mouseout(function(){
          $(".iab").css("background","rgba(0, 183, 228, 0.5)");
          $(".iab h1").css("opacity","1");
          $(".iab p").css("color","#eee");
        });
      });

      $(".modal").on('hidden.bs.modal', function(){
        currentSelection = [];
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
      $(document).on('click', '#realty-main-filter-reset', function(){

        var i,
          areas = $('#select_area').val(),
          developers = $('#select_developer').val(),
          deadline = $('#select_deadline').val(),
          complexes = $('#select_complex').val(),
          type = $('#select_type').val(),
          material = $('#select_material').val(),
          category = $('#select_category').val(),
          balcony = $('#select_balkon').val(),
          metro = $('#select_metro').val();

        // Значения по умолчанию для Слайдеров
        var
          floorMinDefault = 1,
          floorMaxDefault = 30,
          floorMinCur = 1,
          floorMaxCur = 30,

          sqMinDefault = 15,
          sqMaxDefault = 110,
          sqMinCur = 15,
          sqMaxCur = 95,

          priceMinDefault = 30,
          priceMaxDefault = 125,
          priceMinCur = 35,
          priceMaxCur = 100,

          coastMinDefault = 0.5,
          coastMaxDefault = 4.5,
          coastMinCur = 0.9,
          coastMaxCur = 4.5;

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

        for (i in balcony) {
          //@todo Баг. При клике на input не меняется статус checkbox'a
          $('#id-modal_balkon-' + balcony[i]).prop('checked', false);
          $('.modal_balkon-' + balcony[i]).trigger('click');
        }

        for (i in metro) {
          //@todo Баг. При клике на input не меняется статус checkbox'a
          $('#id-modal_metro-' + metro[i]).prop('checked', false);
          $('.modal_metro-' + metro[i]).trigger('click');
        }

        var slider = $(".floor").data("ionRangeSlider");

        slider.update({
          min: floorMinDefault,
          max: floorMaxDefault,
          from:floorMinCur,
          to: floorMaxCur,
          step: 1
        });
        $('#textfield_floor_min').val(floorMinCur);
        $('#textfield_floor_max').val(floorMaxCur);
        $('.search-main-input-floor').val("Все");

        var slider = $(".sq").data("ionRangeSlider");

        slider.update({
          min: sqMinDefault,
          max: sqMaxDefault,
          from: sqMinCur,
          to: sqMaxCur,
          step: 1
        });

        var slider = $(".price").data("ionRangeSlider");

        slider.update({
          min: priceMinDefault,
          max: priceMaxDefault,
          from: priceMinCur,
          to: priceMaxCur,
          step: 1
        });

        var slider = $(".coast").data("ionRangeSlider");

        slider.update({
          min: coastMinDefault,
          max: coastMaxDefault,
          from: coastMinCur,
          to: coastMaxCur,
          step: 0.2
        });

        $('#textfield_cost_max').val('45000000000')

        queryCountResult();
      })

      $('#realty-main-filter-reset').trigger('click');
    })
  };

}(jQuery));