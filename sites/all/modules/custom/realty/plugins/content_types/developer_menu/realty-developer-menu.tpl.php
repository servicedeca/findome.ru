<div class="container fin">
  <div class="col-xs-12 complex-menu zero-padding">
    <?php print $logo;?>
    <div class="col-xs-9 zero-padding complex-header">
      <?php print $button_booking; ?>
      <div class="contact-block">
        <h3>Хотите получить бесплатную консультацию по объектам застройщика?</h3>
        <label>Оставьте заявку, и специалист отдела продаж застройщика свяжется с Вами.</label>
        <p class="fb1_1">
          Оставить заявку
        </p>

      </div>
      <label>Застройщик</label>
      <h1><?php print $developer_name; ?></h1>

      <label>Рейтинг</label>

      <?php print $img_question; ?>

      <div class="progress-rating" onclick="location.href='/developer/<?php print $developer_tid;?>/reviews?p=assessmen'">
        <div style="width:<?php print (int)$rating_value * 20; ?>%"></div>
        <?php print $img_starz; ?>
        <p><span><?php print $rating_value; ?> </span>/ 5</p>
      </div>

      <ul>
        <?php foreach($menu as $item):?>
          <?php print $item;?>
        <?php endforeach;?>
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