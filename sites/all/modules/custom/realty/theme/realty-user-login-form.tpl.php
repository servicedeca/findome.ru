<div class="col-xs-12 modal-search">
  <div class="col-xs-2 input-modal-icon">
    <?php print $image_mail; ?>
  </div>
  <div class="col-xs-8">
    <?php print drupal_render($form['name']);?>
  </div>
</div>
<div class="col-xs-12 modal-search">
  <div class="col-xs-2 input-modal-icon">
    <?php print $image_pass; ?>
  </div>
  <div class="col-xs-8">
    <?php print drupal_render($form['pass']);?>
  </div>
</div>
<div id="login-error">

</div>
<div class="col-xs-12 modal-button mtmb-35">
  <?php print drupal_render($form['actions'])?>
</div>
<div class="element-hidden">
  <?php print drupal_render_children($form);?>
</div>