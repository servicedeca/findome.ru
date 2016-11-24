<div class="container-fluid container-fix margin-top-2">
  <div class="row">
    <div class="col-xs-3 height fiftyminus zero-padding bbl">
      <a href="<?php print $all_news?>">
        <div class="col-xs-12 index-item zero-padding">
          <h1><?php print t('News');?></h1>
          <p><?php print t('Перейти к списку всех новостей'); ?></p>
        </div>
      </a>
    </div>
    <?php if(!empty($view)): ?>
      <?php print $view;?>
    <?php endif?>
    <div id="dtour">
    </div>
  </div>
</div>
