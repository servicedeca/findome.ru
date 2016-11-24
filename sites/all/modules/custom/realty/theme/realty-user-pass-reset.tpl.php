<div class="col-xs-6 col-xs-offset-3">
  <p>Это одноразовый вход для <em class="placeholder"><?php print $user->mail; ?></em>,
    который будет недействителен после <em class="placeholder"><?php print $time; ?></em>.
    Кликните по этой кнопке для входа на сайт и смены своего пароля.<br>
  Вход в аккаунт с использованием этой ссылки может быть выполнен только один раз.</p>
</div>
<div class="col-xs-12 modal-button mtmb-35">
  <?php print render($form['actions'])?>
</div>
<?php print drupal_render_children($form); ?>