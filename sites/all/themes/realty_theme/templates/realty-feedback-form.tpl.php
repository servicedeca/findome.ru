<?php if($form['type']['#value'] == 'callback'): ?>
  <div class="phone-order fb-window callback">
    <?php print $img_close; ?>
    <div class="callback_info">
      <label>Оставьте заявку, и наш менеджер свяжется с вами.</label>
      <?php print render($form['date_time']);?>
      <?php print render($form['name']);?>
      <?php print render($form['phone']);?>
      <?php print render($form['email']);?>
      <?php print render($form['submit']); ?>
    </div>
  </div>
<?php endif; ?>


<?php if($form['type']['#value'] == 'excur'): ?>
  <div class="guide-order fb-window excur">
    <?php print $img_close; ?>
    <div class="excur_info">
      <label>Мы будем рады показать вам стройплощадку, дома и благоустройство.</label>
      <?php print render($form['complexes']); ?>
      <?php print render($form['date_time']);?>
      <?php print render($form['name']);?>
      <?php print render($form['phone']);?>
      <?php print render($form['email']);?>
      <?php print render($form['submit']); ?>
    </div>
  </div>
<?php endif; ?>

<?php if($form['type']['#value'] == 'question'): ?>
  <div class="question-order fb-window question">
    <?php print $img_close; ?>
    <div class="question_info">
      <label>Задайте нам любой интересующий вас вопрос.</label>
      <?php print render($form['question']);?>
      <?php print render($form['name']);?>
      <?php print render($form['phone']);?>
      <?php print render($form['email']);?>
      <?php print render($form['submit']); ?>
    </div>
  </div>
<?php endif; ?>

<?php if($form['type']['#value'] == 'selection'): ?>
  <div class="selection-order fb-window selection review-order">
    <?php print $img_close; ?>
    <div class="selection_info">
      <label>Заполните заявку на подбор квартиры в новостройках, и мы пришлем вам подборку актуальных вариантов от застройщиков.</label>
      <?php print render($form['name']); ?>
      <?php print render($form['phone']); ?>
      <?php print render($form['email']);?>
      <?php print render($form['question']); ?>
      <?php print render($form['submit']); ?>
    </div>
  </div>
<?php endif; ?>

<div style="display: none">
  <?php print drupal_render_children($form); ?>
</div>