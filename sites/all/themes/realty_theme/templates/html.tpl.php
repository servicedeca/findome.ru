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
<?php print $page_top; ?>
<?php print $page; ?>
<?php print $scripts; ?>
<?php print $page_bottom; ?>
</body>
</html>
