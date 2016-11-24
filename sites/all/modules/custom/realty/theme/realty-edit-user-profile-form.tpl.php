<div class="container container-modal-city zero-padding">
  <div class="col-xs-12 header-container-modal header-block">
    <div class="modal-text">
      <p>
        <?php print t('Изменение профиля'); ?>
      </p>
    </div>
    <button type="button" class="close close-modal" data-dismiss="modal" aria-hidden="true">
      <?php print $img_close; ?>
    </button>
  </div>
  <div id="div-info-edit-profile">

  </div>
  <div id="div-container-form">
    <div class="col-xs-12 modal-search">
      <div class="col-xs-2 input-modal-icon">
        <?php print $img_profile; ?>
      </div>
      <div class="col-xs-8">
        <?php print render($form['name']); ?>
      </div>
    </div>
    <div class="col-xs-12 modal-search">
      <div class="col-xs-2 input-modal-icon">
        <?php print $img_mail; ?>
      </div>
      <div class="col-xs-8">
        <?php print render($form['email']); ?>
      </div>
    </div>
    <div class="col-xs-12 modal-search">
      <div class="col-xs-2 input-modal-icon">
        <?php print $img_phone; ?>
      </div>
      <div class="col-xs-8">
        <?php print render($form['phone']); ?>
      </div>
    </div>
    <div class="col-xs-12 modal-search">
      <div class="col-xs-2 input-modal-icon">
        <?php print $img_password; ?>
      </div>
      <div class="col-xs-8">
        <?php print render($form['password']); ?>
      </div>
    </div>
    <div class="col-xs-12 modal-search">
      <div class="col-xs-2 input-modal-icon">
        <?php print $img_password; ?>
      </div>
      <div class="col-xs-8">
        <?php print render($form['password1']); ?>
      </div>
    </div>
    <div class="col-xs-12 modal-button mtmb-35">
      <?php print render($form['submit']); ?>
    </div>

    <div class="element-hidden">
      <?php print drupal_render_children($form); ?>
    </div>
  </div>
  <div>
