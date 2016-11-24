(function ($) {
  Drupal.behaviors.realtyEditUserprofile = {
    attach: $(function(){
      var butEdit,
          inputEditName,
          inputEditPhone,
          inputEditMail;

      var init = function() {
        butEdit = document.getElementsByClassName('profile-edit');
        inputEditPhone = document.getElementById('profile-phone');
        inputEditName = document.getElementById('profile-name');
        inputEditMail = document.getElementById('profile-mail');
      }

      var editValue = function () {
        $(document).on('click', '.profile-edit', function() {
          console.log(inputEditName.value);
          if (inputEditName.value === '' || inputEditPhone.value === '' || inputEditMail === '') {

          }
          else {
            $.ajax({
              url: '/edit_user_profile',
              type: 'POST',
              data: {
                name: inputEditName.value,
                mail: inputEditMail.value,
                phone: inputEditPhone.value
              },
              success: function(response) {
                if (response === '1') {
                  $('#h-name').html(inputEditName.value);
                  $('#h-mail').html(inputEditMail.value);
                  $('#h-phone').html(inputEditPhone.value);
                  $('.close-modal').trigger('click');
                }
                else {
                  alert('error');
                }
              },
              error: function(response) {
                alert('false');
              }
            });
          }
        });
      }

      var closeModal = function() {
        $(document).on('click', '.close-modal', function() {

          inputEditName.value = $('#h-name').html();
          inputEditMail.value = $('#h-mail').html();
          inputEditPhone.value = $('#h-phone').html();

        });
      }

      init();
      editValue();
      //closeModal();
    })
  }


  Drupal.behaviors.realtyDeleteApartments = {
    attach: $(function(){
      $(document).on('click', '.delete-apartment-comprassion', function(){
        var nid = $(this).data('apartment-nid');
        $('.apt-'+nid).remove();
        $.ajax({
          url: '/comprassion_delete',
          type: 'POST',
          data: {
            nid: nid
          },
          success: function(response) {

          },
          error: function(response) {
            alert('false');
          }
        });

      });
    })
  }

  Drupal.behaviors.realtyEditUserprofileForm = {
    attach: $(function(){
      $(document).on('click', '#edit-profile', function() {
        console.log('ok');
        $.ajax({
          url: '/realty_edit_user_profile',
          type: 'POST',
          success: function(response) {
            $('#div-edit-user-profile-form').html(response);
            //$('#realty-edit-user-profile-form').ajaxForm();
            Drupal.attachBehaviors();
          },
          error: function(response) {
            alert('false');
          }
        });
      });

      function simpleAjaxPopupFormProcess() {
        Drupal.attachBehaviors('#realty-edit-user-profile-form');
        $('#realty-edit-user-profile-form').ajaxForm();
      }
    })
  }


  Drupal.behaviors.realtyButGetCertificate = {
    attach: $(function(){
      $('.input-agreement').keyup(function(){
        var agreement = $(this).data('booking-nid'),
            agreementName = $('#input-agreement-name-' + agreement),
            but = $('#but-get-certificate-' + agreement);

        if($(this).val() !== '' && agreementName.val() !== '') {
          console.log(but);
          but.addClass('prize-button-active');
        }
        else {
          but.removeClass('prize-button-active');
        }
      });

      $('.input-agreement-name').keyup(function(){
        var agreement = $(this).data('booking-nid'),
          agreementName = $('#input-agreement-' + agreement),
          but = $('#but-get-certificate-' + agreement);

        if($(this).val() !== '' && agreementName.val() !== '') {
          console.log(but);
          but.addClass('prize-button-active');
        }
        else {
          but.removeClass('prize-button-active');
        }
      });


      $(document).on('click', '.prize-button-active', function() {
        var bookingId = $(this).data('booking-id'),
            inputName = $('#input-agreement-name-' + bookingId),
            inputNum = $('#input-agreement-' + bookingId),
            but = $('#but-get-certificate-' + bookingId),
            data = {
              nid: bookingId
            };

        if (inputName.val !== '' && inputNum !== '') {
          data.name = inputName.val();
          data.number_contract = inputNum.val();
        }

        $.ajax({
          url: '/realty_get_certificate',
          type: 'GET',
          data: {
            data: data
          },
          success: function(response) {
            console.log(response);
            if(response == '1') {
              but.removeClass('prize-button-active')
                 .html('Получить сертификат');

            }
          },
          error: function(response) {
            alert('false');
          }
        });
      });

    })
  }

}(jQuery));