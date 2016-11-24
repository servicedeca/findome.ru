<div id="div-register">
  <div class="col-xs-12 modal-search">
    <div class="col-xs-2 input-modal-icon">
      <?php print $image_mail; ?>
    </div>
    <div class="col-xs-8">
      <?php print drupal_render($form['account']['mail']); ?>
    </div>
  </div>
  <div class="col-xs-12 modal-search">
    <div class="col-xs-2 input-modal-icon">
      <?php print $image_profile; ?>
    </div>
    <div class="col-xs-8">
      <?php print drupal_render($form['field_user_name']); ?>
    </div>
  </div>
  <div class="col-xs-12 modal-search">
    <div class="col-xs-2 input-modal-icon">
      <?php print $image_pass; ?>
    </div>
    <div class="col-xs-8">
      <?php print drupal_render($form['account']['pass']['pass1']); ?>
    </div>
  </div>
  <div class="col-xs-12 modal-search">
    <div class="col-xs-2 input-modal-icon">
      <?php print $image_pass; ?>
    </div>
    <div class="col-xs-8">
      <?php print drupal_render($form['account']['pass']['pass2']); ?>
    </div>
  </div>
  <div class="col-xs-12 error-hint">
    <p>

    </p>
  </div>
  <div class="col-xs-7 col-xs-offset-3 zero-padding modal-confitm" id="input-personal">
    <label>
      <?php print render($form['field_conditions']) ;?>
    </label>
  </div>
  <div class="col-xs-12 modal-button mtmb-35">
    <?php print drupal_render($form['actions']['submit']); ?>
  </div>

  <div class="element-hidden">
    <?php print drupal_render_children($form);?>
  </div>
</div>