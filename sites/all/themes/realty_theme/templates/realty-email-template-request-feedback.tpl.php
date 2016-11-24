<?php print $title; ?><br><br>

Имя: <?php print $name; ?><br>
<?php if ($email): ?>
  Email: <?php print $email; ?><br>
<?php endif; ?>
<?php if ($phone): ?>
  Номер телефона: <?php print $phone; ?><br>
<?php endif; ?>

<?php if (isset($options['date_time'])): ?>
  Желаемое время и дата звонка:  <?php print $options['date_time']; ?><br>
<?php endif; ?>


<?php if (isset($complex)): ?>
  Жилой комплекс:  <?php print $complex; ?><br>
<?php endif; ?>

<?php if (isset($question) && !isset($selection)): ?>
  Вопрос или предложение:  <?php print $question; ?><br>
<?php endif; ?>

<?php if (isset($selection)): ?>
  Заявка на подбор:  <?php print $question; ?><br>
<?php endif; ?>