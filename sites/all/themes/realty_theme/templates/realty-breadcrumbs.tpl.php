<div class="container fin ">
  <div class="col-xs-12 breadcrumb-block margin-top-70">
    <ol class="breadcrumb zero-padding breadcrumbfix">
      <?php foreach($variables['breadcrumb'] as $key => $breadcrumb): ?>
        <?php if (count($variables['breadcrumb']) == $key + 1) :?>
          <?php if (isset($page_title)):?>
            <?php print '<li><a href="#">' . $breadcrumb . '</a></li>'; ?>
            <?php print '<li class="active"><a href="#">' . $page_title . '</a></li>'; ?>
          <?php endif ?>
          <?php if (!isset($page_title)):?>
            <?php print '<li class="active"><a href="#">' . $breadcrumb . '</a></li>'; ?>
          <?php endif ?>
        <?php endif ?>
        <?php if (count($variables['breadcrumb']) != $key + 1) :?>
          <?php print '<li><a href="#">' . $breadcrumb . '</a></li>'; ?>
        <?php endif ?>
      <?php endforeach ?>
    </ol>
  </div>
</div>