
    <div class="col-xs-12 modal-preview-text" id="div-info-box">
      <p>
        Заявка отправляется в отдел продаж застройщика.
        Специалист отдела продаж застройщика свяжется с Вами по указанному в заявке телефону и ответит на все Ваши вопросы.
      </p>
    </div>
    <div id="ajax-div-modal-booking-form">
      <div id="ajax-div-modal-booking-form">
<!--        <div class="col-xs-12 modal-search">-->
<!--          <div class="col-xs-2 input-modal-icon">-->
<!--            --><?php //print $image_mail; ?>
<!--          </div>-->
<!--          <div class="col-xs-8">-->
<!--            --><?php //print render($form['email'])?>
<!--          </div>-->
<!--        </div>-->
        <div class="col-xs-12 modal-search">
          <div class="col-xs-2 input-modal-icon">
            <?php print $image_man; ?>
          </div>
          <div class="col-xs-8">
            <?php print render($form['name'])?>
          </div>
        </div>
        <div class="col-xs-12 modal-search">
          <div class="col-xs-2 input-modal-icon">
            <?php print $image_phone; ?>
          </div>
          <div class="col-xs-8">
            <?php print render($form['number_phone'])?>
          </div>
        </div>
        <!--<div class="col-xs-12 bookmodal-title">
          <p><?php /*print t('Введите паспортные данные'); */?></p>
        </div>
        <div class="col-xs-12 modal-search">
          <div class="col-xs-2 col-xs-offset-2">
            <?php /*print render($form['passport_series']); */?>
          </div>
          <div class="col-xs-3">
            <?php /*print render($form['passport_id']); */?>
          </div>
          <div class="col-xs-3">
            <?php /*print render($form['date_issue']); */?>
          </div>
          <div class=" col-xs-offset-2 col-xs-8">
            <?php /*print render($form['issued_by']); */?>
          </div>
        </div>-->

        <!--
        <div class="col-xs-12 bookmodal-title">
          <p><?php// print t('Выберите менеджера отдела продаж застройщика'); ?></p>
        </div>
        <div id="edit-managers" class="form-radios col-xs-10 col-xs-offset-2 book-managers-block">
          <?php// print render($form['managers']); ?>
        </div>
-->
        <!--
        <div class="col-xs-12 bookmodal-title">
          <p><?php// print t('Выберите способ покупки'); ?></p>
        </div>
        <div class="form-radios col-xs-10 col-xs-offset-2 book-managers-block">
          <?php// print render($form['payment']); ?>
        </div>
        -->

        <div id="div-mortgage-applications" class="col-xs-7 col-xs-offset-3 zero-padding modal-confitm mb35">
          <label>
            <?php print render($form['mortgage_applications']); ?>
          </label>
        </div>

        <div style="display: none" class="col-xs-12 bookmodal-title">
          <p><?php print t('Загрузите документы'); ?></p>
          <label><?php print t('Вы можете загрузить скан вашего паспорта и одобрительное решение банка,'); ?><br><?php print t('если оно имеется.'); ?></label>
        </div>

        <div style="display: none"  class="col-xs-8 col-xs-offset-2">
          <?php print render($form['documents']);?>
        </div>

        <div class="col-xs-7 col-xs-offset-3 zero-padding modal-confitm" id="input-personal">
          <label>
            <?php print render($form['personal']); ?>
          </label>
        </div>

<!--        <div class="col-xs-7 col-xs-offset-3 zero-padding modal-confitm mb35">-->
<!--          <label>-->
<!--            --><?php //print render($form['correct']); ?>
<!--          </label>-->
<!--        </div>-->
        <div class="col-xs-12 credit-modal-button">
          <?php print render($form['submit']);?>
        </div>

      </div>
    </div>

<div class="element-hidden">
  <?php print drupal_render_children($form); ?>
</div>