(function ($) {
Drupal.behaviors.realtyApartmentFilter = {
  attach: $(function() {
    $(document).on('hidden.bs.modal', ".modal", function() {
      console.log('fefefefef');
      $('#edit-submit-apartments').trigger('click');
    });

    var logic = false; //@todo Баг. Некорректный статус checkbox'a
    var call_from_home = false;
    var call_from_section = false;
    var call_from_clear = false;

    var initFilters = function () {
      var
        floorMin = $('#edit-field-apartment-floor-value-min').val(),
        floorMax = $('#edit-field-apartment-floor-value-max').val(),
        sqMin = $('#edit-field-gross-area-value-min').val(),
        sqMax = $('#edit-field-gross-area-value-min').val();

      console.log($("body .sq").length);
      //Заполняем модальное окно и кнопку фильтра площадь
      $(".sq").ionRangeSlider({
        hide_min_max: true,
        keyboard: true,
        min: 1,
        max: 200,
        from: sqMin != 0 ? sqMin: 1,
        to: sqMax != 0 ? sqMax: 200,
        type: 'double',
        step: 1,
        grid: true,
        max_postfix: "+"
      });

      //Заполняем модальное окно и кнопку фильтра этаж
      $(".floor").ionRangeSlider({
        hide_min_max: true,
        keyboard: true,
        min: 1,
        max: 30,
        from: floorMin ? floorMin : 1,
        to: floorMax ? floorMax : 30,
        type: 'double',
        step: 1,
        grid: true,
        hasGrid: true,
        max_postfix: "+"
      });

      $('#modal_sq-from_value').html(1+'<span>до</span>');
      $('#modal_sq-to_value').html(200);

      $('#modal_floor-from_value').html(1+'<span>до</span>');
      $('#modal_floor-to_value').html(30);
    }


    var multiselect_modal = function(class_check_box, id_select, class_input) {
      var array_input = {};
      var string_input = '';
      $(document).on('click', '.'+class_check_box, function(){
        var param =  $(this).val().split(';');

        if ($(this).prop("checked") == logic ) {
          $('#'+id_select+' option[value='+param[0]+']').attr('selected', 'selected');
          $('#'+id_select+' option[value='+param[0]+']').prop('selected', true);
          array_input[param[1]] = param[1];

          /*            if (class_check_box == 'CheckboxDeveloper') {
           devid[param[0]] = param[0];
           $('.search-input-complex').val('');
           complex_select(devid);
           }*/

          string_input = '';
          $.each(array_input, function(key, val) {
            string_input == '' ?  string_input = val : string_input += ', '+val;
          });
          $('.'+class_input).val(string_input);

          if (class_check_box == 'CheckboxAddress') {
            var home_id = $(this).val().split(';');

            if (!call_from_section) {
              call_from_home = true;

              $('.modal_section-'+home_id[0]).prop('checked',true);
              $('.modal_section-'+home_id[0]).trigger('click');

              call_from_home = false;
            }
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

          /*            if (class_check_box == 'CheckboxDeveloper') {
           delete devid[param[0]];
           $('.search-input-complex').val('');
           complex_select(devid);
           }*/

          if (class_check_box == 'CheckboxAddress') {
            var home_id = $(this).val().split(';');

            call_from_home = true;

            if (!call_from_section) {
              $('.modal_section-'+home_id[0]).prop('checked',false);
              $('.modal_section-'+home_id[0]).trigger('click');
            }
            call_from_home = false;
          }
        }
      });
    }

    $(document).on('click', '.check-book', function() {
      var checkbox = $(this).find('input[type=checkbox]');
      if(checkbox.prop("checked")){
        $(this).removeClass("check-book-active");
        checkbox.prop("checked", false);
        $('#edit-field-status-value [value=All]').attr('selected', 'selected');
        $('#edit-submit-apartments').trigger('click');
      }else{
        $(this).addClass("check-book-active");
        checkbox.prop("checked", true);
        $('#edit-field-status-value [value=1]').attr('selected', 'selected');
        $('#edit-submit-apartments').trigger('click');
      }
    });

    $(document).on('change', ".sq", function(){
      wall = $(this).val();
      wall = wall.split(';');
      $('#edit-field-gross-area-value-min').val(wall[0]);
      $('#edit-field-gross-area-value-max').val(wall[1]);


      string_input = new String(wall[0])+' - '+new String(wall[1])+' кв. м.';
      $(".search-input-sq").val(string_input);

      $('#modal_sq-from_value').html(wall[0]+'<span>до</span>');
      $('#modal_sq-to_value').html(wall[1]);

    });

    $(document).on('change', ".floor", function() {

      wall = $(this).val();
      wall = wall.split(';');
      $('#edit-field-apartment-floor-value-min').val(wall[0]);
      $('#edit-field-apartment-floor-value-max').val(wall[1]);

      string_input = new String(wall[0])+' - '+new String(wall[1]);
      $(".search-input-floor").val(string_input);

      $('#modal_floor-from_value').html(wall[0]+'<span>до</span>');
      $('#modal_floor-to_value').html(wall[1]);

    });

    $(document).on('click', '.filter-clear', function () {
      var
        i,
        addresses = $('#edit-field-apartament-home-tid').val(),
        rooms = $('#edit-field-number-rooms-value').val();

      logic = true;
      call_from_clear = true;

      for (i in addresses) {
        //@todo Баг. При клике на input не меняется статус checkbox'a
        $('.modal_address-' + addresses[i]).trigger('click');
        $('.label-modal_address-' + addresses[i]).trigger('click');
        $('#id-modal_address-' + addresses[i]).prop('checked', false);
      }

      for (i in rooms) {
        //@todo Баг. При клике на input не меняется статус checkbox'a
        $('#id-modal_type-' + rooms[i]).trigger('click');
        $('.label-modal_type-' + rooms[i]).trigger('click');
        $('#id-modal_type-' + rooms[i]).prop('checked', false);

      }

      logic = false;
      call_from_clear = false;


      //Очищаем модальное окно и поле фильтра Площадь
      var slider = $(".floor").data("ionRangeSlider");

      slider.update({
        from: 1,
        to: 200
      });
      $('#edit-field-gross-area-value-min').val('');
      $('#edit-field-gross-area-value-max').val('');

      //Очищаем модальное окно и поле фильтра Этаж
      var slider = $(".sq").data("ionRangeSlider");

      slider.update({
        from: 1,
        to: 200
      });

      $('#edit-field-apartment-floor-value-min').val('');
      $('#edit-field-apartment-floor-value-max').val('');


      //Очищаем поле фильтра Не показывать забронированные
      var checkbox = $('.check-book').find('input[type=checkbox]');

      if (checkbox.prop("checked")) {
        $('.check-book').trigger('click');
      }

      $('#edit-submit-apartments').trigger('click');
    });

    $(document).on('click', '.search-button', function() {
      $('#edit-submit-apartments').trigger('click');
    });

    var multiselect_regular_modal = function(class_check_box, id_select, class_input) {
      var array_input = {};
      var string_input = '';
      $(document).on('click', '.'+class_check_box, function(){

        var param =  $(this).val().split(';');

        if ($(this).prop("checked") == logic && !call_from_clear || $(this).prop("checked") == false && call_from_clear) {

          var value = param[0].split('-');
          value[0] = value[0].replace(/\_/gi, ".");
          array_input[value[0]] = value[0];

          string_input = '';
          $('#'+id_select).val('');

          var i = 0;
          var string_out = '';

          $.each(array_input, function(key, val) {
            i++;

            if (i != Object.keys(array_input).length) {
              string_out = $('#'+id_select).val() + '^' + val + '$' + '|';
            } else {
              string_out = $('#'+id_select).val() + '^' + val + '$';
            }

            $('#'+id_select).val(string_out);
            string_input == '' ?  string_input = val : string_input += ', '+val;
          });

          if (class_check_box == 'CheckboxSection') {
            var section_id = $(this).val().split(';');
            var home_id = section_id[0].split('-');

            if ($('#id-modal_address-'+home_id[1]).prop("checked") == false ) {

              if (!call_from_home && !call_from_clear) {
                call_from_section = true;

                $('#id-modal_address-' + home_id[1]).prop('checked', true);
                $('#id-modal_address-' + home_id[1]).trigger('click');

                call_from_section = false;
              }

              $('#edit-field-apartament-home-tid option[value='+home_id[1]+']').attr('selected', true);
            }
          }

          $('.'+class_input).val(string_input);
        }
        else {
          var value = param[0].split('-');

          delete array_input[value[0]];

          string_input = '';
          $('#'+id_select).val('');

          var i = 0;
          var string_out = '';

          $.each(array_input, function(key, val) {
            i++;

            if (i != Object.keys(array_input).length) {
              string_out = $('#'+id_select).val() + val + '|';
            } else {
              string_out = $('#'+id_select).val() + val;
            }

            $('#'+id_select).val(string_out);
            string_input == '' ?  string_input = val : string_input += ', '+val;
          });

          if (class_check_box == 'CheckboxSection') {
            var section_id = $(this).val().split(';');
            var home_id = section_id[0].split('-');

            var section_array = $('#home_id-'+home_id[1]).data('sections').split(';');

            var checked = false;

            if (!call_from_home && !call_from_clear) {


              $('#id-modal_section-'+section_id[0]).attr('selected', false);

              for (i = 0; i < Object.keys(section_array).length; i++) {
                if ($('#id-modal_section-' + section_array[i]).prop('checked') == true && section_array[i] != section_id[0]) {
                  checked = true;
                  break;
                }
              }

              if (!checked) {
                call_from_section = true;

                $('.label-modal_address-' + home_id[1]).click();

                $('#id-modal_address-' + home_id[1]).trigger('click');
                $('.label-modal_address-' + home_id[1]).trigger('click');
                $('#id-modal_address-' + home_id[1]).prop('checked', false);

                call_from_section = false;

                $('#edit-field-apartament-home-tid option[value='+home_id[1]+']').attr('selected', false);
              }
            }
          }

          string_input == '' ? string_input = Drupal.t('Все') : string_input;
          $('.'+class_input).val(string_input);
        }
      });
    }

    setTimeout(function(){initFilters();},500)


    multiselect_modal('CheckboxRoom', 'edit-field-number-rooms-value');
    multiselect_modal('CheckboxAddress', 'edit-field-apartament-home-tid');
    multiselect_modal('CheckboxDeveloper', 'edit-field-complex-developer-tid');

    multiselect_regular_modal('CheckboxSection', 'edit-field-section-value');
  })
}


  Drupal.behaviors.realtyFindApartmentNumber = {
    attach: $(function(){

      $(document).on('change', '#find-number-apartment', function(){
        console.log('ch');
        $('#edit-field-number-apartament-value').val($(this).val());
      });

      $(document).on('click', '#find-number-apartment-button', function() {
        console.log('chb');
        $('#edit-submit-apartments').trigger('click');
      });

    })
  }
  //end.
}(jQuery));