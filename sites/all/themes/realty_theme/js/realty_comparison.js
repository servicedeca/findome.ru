(function ($) {

  Drupal.attachBehaviors();

  Drupal.behaviors.realtyComparison = {
    attach: $(function () {

      console.log(Drupal.settings.apartments_info);

      var changeAptIdOld;
      var changeAptIdNew;

      var comparisonPrint = function (apartmentsInfoKeys) {
        console.log('print')
        var i = 0;
        $('#apt-other').html('');

        apartmentsInfoKeys.forEach(function(apartmentNid, apartmentId) {

          var apartmentInfo = apartmentsInfo[apartmentNid];

          // Вывод инфорации о первых двух квартирах в массиве
          if (i < 2) {
            console.log($('#comparison_apt_'+i).find('.realty-appartment-info').length);
            $('#comparison_apt_'+i).find('.realty-appartment-info').attr('data-id', apartmentInfo.nid);
            $('#comparison_apt_'+i).find('.apt-change').attr('data-apt-id', apartmentInfo.nid);

            $('#comparison_apt_'+i).find('.apt-apt').html('<h1>Квартира<span>'+apartmentInfo.number+'</span></h1>');
            $('#comparison_apt_'+i).find('.apt-plan').html(apartmentInfo.plan_300x200);
            $('#comparison_apt_'+i).find('.apt-status').html(apartmentInfo.status ? '' : 'Забронирована');
            $('#comparison_apt_'+i).find('.apt-sq').html(apartmentInfo.sq);
            $('#comparison_apt_'+i).find('.apt-section').html(apartmentInfo.section);
            $('#comparison_apt_'+i).find('.apt-coast').html(apartmentInfo.coast.replace(/(\d)(?=(\d\d\d)+([^\d]|$))/g, '$1 '));
            $('#comparison_apt_'+i).find('.apt-rooms').html(apartmentInfo.rooms+' комнатная');
            $('#comparison_apt_'+i).find('.apt-complex').html(apartmentInfo.complex);
            $('#comparison_apt_'+i).find('.apt-floor').html(apartmentInfo.floor);
            $('#comparison_apt_'+i).find('.apt-price').html(apartmentInfo.price.replace(/(\d)(?=(\d\d\d)+([^\d]|$))/g, '$1 '));
            $('#comparison_apt_'+i).find('.apt-material').html(apartmentInfo.material);
            $('#comparison_apt_'+i).find('.apt-deadline').html(apartmentInfo.deadline_quarter+' квартрал 20'+apartmentInfo.deadline_year);
            $('#comparison_apt_'+i).find('.apt-ceiling').html(apartmentInfo.ceiling_height);
            $('#comparison_apt_'+i).find('.apt-parking').html(apartmentInfo.parking ? 'Есть' : 'Нет');
            $('#comparison_apt_'+i).find('.apt-developer').html(apartmentInfo.developer);
            $('#comparison_apt_'+i).find('.apt-address').html(apartmentInfo.address);

            if (apartmentInfo.balkon) {
              $('#comparison_apt_'+i).find('.apt-balkon').html('Балкон');
            } else if (apartmentInfo.loggia) {
              $('#comparison_apt_'+i).find('.apt-balkon').html('Лоджи');
            } else if (apartmentInfo.balkon_loggia) {
              $('#comparison_apt_'+i).find('.apt-balkon').html('Балкон + Лоджия');
            }
          }
          // Вывод информации об остальных квартирах
          else {
            var imgDelete = '<svg version="1.1" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" width="12.528px" height="12.528px" viewBox="0 0 12.528 12.528" enable-background="new 0 0 12.528 12.528" xml:space="preserve">' +
              '<polygon fill="#FFFFFF" points="10.77,0 6.264,4.506 1.759,0 0,1.759 4.506,6.264 0,10.77 1.758,12.528 6.264,8.023 10.77,12.528 12.528,10.77 8.023,6.264 12.528,1.759 		"/>' +
              '</svg>';

            var comparisonDelete = '<div class="cross-csi apt-delete delete-apartment-comprassion" data-apartment-nid="'+apartmentInfo.nid+'">'+imgDelete+'</div>';

            var imgButton = '<svg version="1.1" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" width="25px" height="7.5px" viewBox="0 0 20.519 6.085" enable-background="new 0 0 20.519 6.085" xml:space="preserve">' +
              '<polygon fill="#EFEFEF" points="11.352,0 0,3.04 11.352,6.085 11.352,3.75 20.519,3.75 20.519,2.335 11.352,2.335"/>' +
              '</svg>';

            var comparisonButton = '<div class="col-xs-2"><div class="compression-button" data-apt-id="'+apartmentInfo.nid+'">'+imgButton+'</div></div>';
            var aptPlan = '<div class="col-xs-5 realty-appartment-info" data-toggle="modal" data-target=".flat_modal" data-id="'+apartmentInfo.nid+'">'+apartmentInfo.plan_170x130+'</div>';

            var aptNumber = '<h1>квартира<span>'+apartmentInfo.number+'</span></h1>';
            var aptStatus = '<h2>'+apartmentInfo.status ? '' : 'Забронирована'+'</h2>';

            var aptRoomsPostfix = apartmentInfo.rooms.indexOf('c') + 1 ? '' : 'К';
            var aptRoomsSq = '<h3>'+apartmentInfo.rooms+aptRoomsPostfix+'&nbsp;&nbsp;<span>'+apartmentInfo.sq+'<span>м<sup>2</sup></h3>';
            var aptCoast = '<h4>'+apartmentInfo.coast.replace(/(\d)(?=(\d\d\d)+([^\d]|$))/g, '$1 ')+' <span>руб.</span></h4>';
            var aptComplex = '<p>'+apartmentInfo.complex+'</p>';

            var aptInfo = '<div class="col-xs-5 realty-appartment-info" data-toggle="modal" data-target=".flat_modal" data-id="'+apartmentInfo.nid+'">'+aptNumber+aptStatus+aptRoomsSq+aptCoast+aptComplex+'</div>';

            var aptBlock = '<div class="col-xs-12 comprassion-slider-item" id="csi'+apartmentInfo.nid+'">'+
              comparisonDelete+comparisonButton+aptPlan+aptInfo+
              '</div>';

            $('#apt-other').append(aptBlock);
          }
          i++;
        })
        Drupal.attachBehaviors();
      }

      var comparisonSwap = function (apartmentNidOld, apartmentNidNew) {

        var NewId,
          OldId,
          tmp;

        OldId = jQuery.inArray(String(apartmentNidOld), apartmentsInfoKeys);
        NewId = jQuery.inArray(String(apartmentNidNew), apartmentsInfoKeys);
        tmp = apartmentsInfoKeys[OldId];

        apartmentsInfoKeys[OldId] =  apartmentsInfoKeys[NewId];
        apartmentsInfoKeys[NewId] = tmp;
      }

      var comparisonDelete = function (apartmentNid) {

        // Удаление квартиры из общего массива
        delete apartmentsInfo[apartmentNid];

        // Переобпределние массива с ключами квартир
        apartmentsInfoKeys = Object.keys(apartmentsInfo);
      }

      var cmpBtnClicked = false;
      var cpmBtnPreAptId;
      ;
      // Выбор квартиры для сравнения
      $(document).on('click', ".compression-button", function(){
        changeAptIdOld = $(this).attr('data-apt-id');

        if (cmpBtnClicked != true) {
          cmpBtnClicked = true;

          $(".compression-button").css("background","#4c4c4c");
          $(".compression-button").css("border","2px solid #939393");

          $(".comprassion-bg-two").css("display","inline");
          $(".comprassion-bg").css("display","inline");

          $('#csi'+changeAptIdOld+'.comprassion-slider-item').css("opacity","1");

          $(this).css("background","#00b7e4");
          $(this).css("border","2px solid #00b7e4");

          cpmBtnPreAptId = changeAptIdOld;
        }
        else {
          cmpBtnClicked = false;

          $(".compression-button").css("background","");
          $(".compression-button").css("border","");

          $(".comprassion-bg-two").css("display","none");
          $(".comprassion-bg").css("display","none");

          $('#csi'+cpmBtnPreAptId+'.comprassion-slider-item').css("opacity","");

          if (changeAptIdOld != cpmBtnPreAptId) {
            $(".compression-button[data-apt-id="+changeAptIdOld+"]").trigger('click');
          }
        }
      });

      if (Drupal.settings.apartments_info) {
        var apartmentsInfo = Drupal.settings.apartments_info;
        var apartmentsInfoKeys = Object.keys(apartmentsInfo);

        setTimeout(function(){
          comparisonPrint(apartmentsInfoKeys);
        },100)
      }

      // Выбор заменяемой квартиры
      $(document).on('click', ".apt-change", function() {
        changeAptIdNew = $(this).attr('data-apt-id');

        $(".compression-button").css("background","");
        $(".compression-button").css("border","");

        $(".comprassion-bg-two").css("display","none");
        $(".comprassion-bg").css("display","none");

        $('#csi'+changeAptIdNew+'.comprassion-slider-item').css("opacity","");

        comparisonSwap(changeAptIdOld, changeAptIdNew);

        comparisonPrint(apartmentsInfoKeys);
      })

      // Удаление квартиры из списка сравнения
      $(document).on('click', ".apt-delete", function () {
        var deleteAptId = $(this).attr('data-apartment-nid');

        comparisonDelete(deleteAptId);

        comparisonPrint(apartmentsInfoKeys);

        // Если пользователь не авторизован
        if (Drupal.settings.comparison_from_cookie == true) {
          var basketStr = JSON.stringify(apartmentsInfoKeys);

          $.cookie('comparison', basketStr, {
            expires: 365,
            path: '/'
          });
        }
        // Если пользователь авторизован
        else {
          $.ajax({
            url: '/comprassion_delete',
            type: 'POST',
            data: {
              nid: deleteAptId
            },
            success: function(response) {

            },
            error: function(response) {
              alert('false');
            }
          });
        }
      })
    })
  }

}(jQuery));