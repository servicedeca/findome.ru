<?php print render($form['title'])?>
<?php print render($form['field_complex_logo'])?>
<?php print render($form['field_complex_mini_logo'])?>
<?php print render($form['field_slogan']);?>
<?php print render($form['field_description'])?>
<?php print render($form['field_complex_developer'])?>
<?php print render($form['field_main_photo'])?>
<?php print render($form['field_photos_complex'])?>
<?php print render($form['field_area'])?>
<?php print render($form['field_address'])?>
<?php print render($form['field_plan_complex'])?>

<h1>
  <?php print t('Очереди строительства')?>
</h1>
<div id="add-queue-plan" class="butt-mark" data-id-complex="<?php print $form['#node']->nid; ?>">
  <?php print t('Отметить очереди строительства на плане ЖК')?>
</div>
<div id="add-queue-plan-save" class="butt-mark">
  <?php print t('Сохранить')?>
</div>
<div id="mark-tools">
  <?php print $tool_add_queue; ?>
</div>
<div class="div-plan-complex-queue">

</div>

<div class="element-hidde">
  <?php print drupal_render_children($form)?>
</div>