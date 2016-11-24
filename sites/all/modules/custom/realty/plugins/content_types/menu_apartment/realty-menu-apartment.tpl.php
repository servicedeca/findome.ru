<div class="container fin">
  <div class="col-xs-12 ap-block zero-padding">

    <div href="apartment.html" class="col-xs-4 ap-name zero-padding">
      <h2>
        Квартира<span><?php print $apartment_number; ?></span>
      </h2>
    </div>

    <div class="col-xs-4 zero-padding text-right">
      <div id="booking-button" class="col-xs-4 ap-button" rel="tooltip" data-placement="left" title="Заявка отправляется в отдел продаж застройщика. Специалист отдела продаж застройщика свяжется с Вами по указанному в заявке телефону и ответит на все Ваши вопросы.">
        <?php print $button_booking; ?>
      </div>
      <div class="col-xs-4 ap-button" id="id_comparison" data-nid-apartment="<?php print $nid;?>">
        <?php print $button_comparsion; ?>
      </div>
      <div class="col-xs-4 ap-button" id="download-id-apartment" data-nid-apartment="<?php print $nid;?>">
      <div>
        <?php print $img_pdf; ?>
      </div>
      <p class="s-label-small">
        Cохранить<br> в PDF
      </p>
    </div>
  </div>

    <div class="contact-block contact-block-ap col-xs-3">
      <h3>Понравилась квартира?</h3>

      <label>забронируйте квартиру в режиме online напрямую у застройщика</label>

    </div>

  <div class="col-xs-2 ap-status zero-padding">
    <p>Статус</p>
    <div id='apart-status'>
      <?php if ($apartment_status == 0): ?>
        <h2 class="s_book">Забронирована</h2>
      <?php elseif ($apartment_status == 1): ?>
        <h2 class="s_free">Свободна</h2>
      <?php endif; ?>
    </div>
  </div>

  <div class="col-xs-2 ap_complex-logo zero-padding">
    <p>Жилой комплекс</p>
    <?php print $complex_logo; ?>
  </div>

  <div href="apartment.html" class="col-xs-12 ap-menu zero-padding">
    <ul>
      <?php foreach($menu as $item):?>
        <?php print $item?>
      <?php endforeach?>
    </ul>
  </div>

</div>
</div>
<?php if(isset($booking_form)): ?>
  <div class="modal fade modal_free" tabindex="-1" role="dialog" aria-labelledby="mySmallModalLabel" aria-hidden="true">
    <div class="container container-modal-city zero-padding">
      <div class="col-xs-12 header-container-modal header-block margin-bottom-50">
        <div class="modal-text">
          <p><?php print t('Заявка на бронирование'); ?></p>
        </div>
        <button type="button" class="close close-modal" data-dismiss="modal" aria-hidden="true">
          <?php print $img_close; ?>
        </button>
      </div>
      <?php print render($booking_form); ?>
    </div>
  </div>
<?php endif; ?>