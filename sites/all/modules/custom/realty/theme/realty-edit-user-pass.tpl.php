<div class="col-xs-6 col-xs-offset-3">
  <label id="massage-user-reset"></label>
</div>
<div class="col-xs-8 col-xs-offset-2 modal-search">
  <div class="col-xs-2 input-modal-icon">
    <?php print $image_mail; ?>
  </div>
  <div class="col-xs-8">
    <?php print render($form['name']); ?>
  </div>
</div>
<div class="col-xs-6 col-xs-offset-3">
  <p>Введите адрес электронной почты на который вам будет отправлена ссылка для изменения пароля</p>
</div>
<div class="col-xs-12 modal-button mtmb-35">
  <?php print render($form['actions'])?>
</div>
<?php print drupal_render_children($form); ?>