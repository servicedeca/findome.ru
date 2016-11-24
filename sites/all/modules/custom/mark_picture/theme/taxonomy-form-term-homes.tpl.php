<?php print render($form['name'])?>
<?php print render($form['description'])?>
<?php print render($form['field_address_house'])?>
<?php print render($form['field_number_home']);?>
<?php print render($form['field_home_complex'])?>
<?php print render($form['field_masonry'])?>
<?php print render($form['field_number_floor'])?>
<?php print render($form['field_map'])?>
<?php print render($form['field_category'])?>
<h1>
<?php print t('Расположение на плане жк')?>
</h1>
<div id="add-home-plan" class="butt-mark">
  <?php print t('Oтметить дом на плане ЖК')?>
</div>
<div id="add-home-plan-save" class="butt-mark">
  <?php print t('Сохранить')?>
</div>
<div id="mark-tools">
  <?php print $tool_add_complex?>
</div>
<div class="div-plan-complex">

</div>

<h1>
  <?php print t('Расположение Секций')?>
</h1>
<?php print render($form['field_home_plan']) ?>
<div id="add-section-plan" class="butt-mark">
  <?php print t('Oтметить секцию на плане дома')?>
</div>
<div id="save-add-section-plan" class="butt-mark">
  <?php print t('Сохранить')?>
</div>

<div id="mark-tools">
  <?php print $tool_add_section?>
  <?php print $tool_add_queue; ?>
</div>
<div class="div-plan-home">

</div>

<?php print render($form['field_plan_floor'])?>
<?php //print render($form['field_home_section'][LANGUAGE_NONE][0]['field_lage_plan_home'])?>
<?php //print render($form['field_home_section']['und']['add_more']) ?>
<?php //print render($form['field_home_section'])?>

<h1>
  <?php print t('Расположение квартир')?>
</h1>
<div id="add-apartments-plan">
  <?php print t('Oтметить квартиры')?>
</div>
<div id="save-apartments-plan" class="butt-mark">
  <?php print t('Сохранить')?>
</div>

<div id="add-apartments-plan-form">
</div>



<div class="element-hidde">
  <?php print drupal_render_children($form)?>
</div>