<!DOCTYPE html>
<html>
<head profile="<?php print $grddl_profile; ?>">
  <meta name="google-site-verification" content="UyTz0NKqvljZhwYK0I7dnWp3XYHXg2pOOEJHvRsZ918" />
  <?php print $head;  ?>
  <title>
    <?php if(arg(0) == 'user' && arg(1) != 'password'): ?>
      <?php print t('Личный кабинет') . ' | ' . variable_get('site_name'); ?>
    <?php else :?>
      <?php print $head_title; ?>
    <?php endif; ?>
  </title>
  <?php print $styles; ?>
</head>
<body class="<?php print $classes; ?>" <?php print $attributes;?>>
<div class="download-container">
    <img src="http://novosibirsk.findome.ru/sites/all/themes/realty_theme/images/minilogo.svg">
    <p>Квартира в клике от вас</p>
    <div id="fountainG">
        <div id="fountainG_1" class="fountainG"></div>
        <div id="fountainG_2" class="fountainG"></div>
        <div id="fountainG_3" class="fountainG"></div>
        <div id="fountainG_4" class="fountainG"></div>
        <div id="fountainG_5" class="fountainG"></div>
        <div id="fountainG_6" class="fountainG"></div>
        <div id="fountainG_7" class="fountainG"></div>
        <div id="fountainG_8" class="fountainG"></div>
    </div>

</div>
<?php print $page_top; ?>
<?php print $page; ?>
<?php print $scripts; ?>
<?php print $page_bottom; ?>

</body>
</html>
