<div class="feedback-open">
  <p>Обратная связь</p>
</div>
<div class="feedback-menu">
  <li class="fb_i fb1">Заказать звонок</li>
  <li id="fb2" class="fb_i">Записаться на экскурсию</li>
  <li id="fb3" class="fb_i">Задать вопрос или оставить отзыв</li>
  <li id="fb4" class="fb_i">Заявка на подбор</li>
  <?php print $img_close; ?>

  <?php print render($request_callback_form)?>
  <?php print render($request_excur_form)?>
  <?php print render($request_question_form)?>
  <?php print render($request_selection_form)?>

</div>