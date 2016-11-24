<div class="col-xs-12 header-container-modal-credit header-block">
  <div class="vertical">
    <h2>Заявка на получение ипотеки</h2>
  </div>
  <button type="button" class="close close-modal" data-dismiss="modal" aria-hidden="true">
    <?php print $img_close; ?>
  </button>
</div>

<div class="col-xs-12 zero-padding bank-line">
  <div class="col-xs-3 bank-line-image" id="bank-id-need">
    <?php print $img_bank_logo; ?>
  </div>
</div>

<div class="col-xs-12" id="hint-box">
</div>

<div class="col-xs-12" id="info-box">

  <h4><?php print t('Заёмщик'); ?></h4>
  <div class="col-xs-12 body-modal-line" id="input-full_name">
    <?php print drupal_render($form['full_name']); ?>
  </div>

  <div class="col-xs-12 body-modal-line" id="input-age">
    <?php print drupal_render($form['age']); ?>
  </div>

  <div class="col-xs-12 body-modal-line" id="input-mobile_phone">
    <?php print drupal_render($form['mobile_phone']); ?>
  </div>

  <div class="col-xs-12 body-modal-line">
    <?php print drupal_render($form['home_phone']); ?>
  </div>

  <div class="col-xs-12 body-modal-line" id="input-email">
    <?php print drupal_render($form['email']); ?>
  </div>

  <div class="col-xs-12 bookmodal-title">
    <p><?php print t('Введите паспортные данные'); ?></p>
  </div>
  <div class="col-xs-12 modal-search">
    <div class="col-xs-2 col-xs-offset-2">
      <?php print render($form['passport_id']); ?>
    </div>
    <div class="col-xs-3">
      <?php print render($form['passport_series']); ?>
    </div>
    <div class="col-xs-3">
      <?php print render($form['date_issue']); ?>
    </div>
    <div class=" col-xs-offset-2 col-xs-8">
      <?php print render($form['issued_by']); ?>
    </div>
  </div>

  <h4><?php print t('Кредитование'); ?></h4>
  <div class="col-xs-12 body-modal-bigline" >
    <label><?php print t('Cумма кредитования'); ?></label>
    <div class="col-xs-6 fix-div incorrect-input">
      <p><?php print t('Заявка на выбранную квартиру'); ?></p>
      <?php print render($form['apartment']); ?>
    </div>

    <?php if (isset($form['mortgage_booking'])): ?>
    <div class="col-xs-6 fix-div incorrect-input" id="input-amount">
      <?php else: ?>
      <div class="col-xs-6 fix-div" id="input-amount">
    <?php endif?>
        <p><?php print t('Требуемая сумма'); ?></p>
        <?php print render($form['amount']); ?>
        <span>руб.</span>
      </div>
    </div>

    <div class="col-xs-12 body-modal-line body-modal-miniline-fix" id="input-period">
      <label>Срок кредитования</label><?php print render($form['period']); ?>
      <span>лет</span>
    </div>

    <div class="col-xs-12 body-modal-line body-modal-line-fix" id="input-payment">
      <label>Первоначальный взнос</label><?php print render($form['payment']); ?>
      <span>руб.</span>
    </div>

    <div class="col-xs-12 body-modal-line body-modal-line-fix" id="input-income">
      <label>Ежемесячный доход</label><?php print render($form['income']); ?>
      <span>руб.</span>
    </div>

    <div class="col-xs-12 body-modal-radio" id="input-confirm_conf">
      <span>Форма подтверждения</span>
      <?php print render($form['confirmation']); ?>

    </div>

    <div class="col-xs-12 body-modal-radio modal-radio-fix" id="input-last_experience">
      <span>Стаж на последнем месте<br> работы</span>
      <?php print render($form['last_experience']); ?>
    </div>

    <div class="col-xs-12 body-modal-radio modal-radio-fix span-fix" id="input-total_experience">
      <span>Общий стаж работы</span>
      <?php print render($form['total_experience']); ?>
    </div>

    <div class="col-xs-12 modal-radio-filial-fix">
      <span><?php print t('Выберите отделение банка:'); ?></span>
      <?php print render($form['cities']); ?>

      <div id="affiliate-box" class="col-xs-8 col-xs-offset-4 filials-block" id="input-affiliate">
        <?php print render($form['affiliate']); ?>
      </div>

    </div>

    <div class="col-xs-7 col-xs-offset-3 zero-padding modal-confitm" id="input-personal">
      <label>
        <?php print render($form['personal']); ?>
      </label>
    </div>

    <div class="col-xs-7 col-xs-offset-3 zero-padding modal-confitm">
      <label>
        <?php print render($form['correct']); ?>
      </label>
    </div>

    <div class="col-xs-7 col-xs-offset-3 zero-padding modal-confitm mb35">
      <label>
        <?php print render($form['mortgage_booking']); ?>
      </label>
    </div>
    <div id="mortgage-form-bookings">
      <div class="col-xs-12 bookmodal-title">
        <p><?php print t('Выберите менеджера отдела продаж'); ?></p>
      </div>
      <div id="edit-managers" class="form-radios col-xs-8 col-xs-offset-2 book-managers-block mb35 ">
        <?php print render($form['managers']); ?>
      </div>
    </div>

    <div class="col-xs-12 modal-button">
      <?php print render($form['mortgage-request-submit']); ?>
    </div>

  </div>

<?php print drupal_render_children($form); ?>