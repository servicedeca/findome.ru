<div class="container fin">
  <div class="col-xs-6 header-menu">
    <h1><?php print t('Новости'); ?></h1>
  </div>
</div>

<div class="container-fluid container-fix all-complex-block">
  <div class="ap-header-layer-top h15">
  </div>
  <div class="container fin mb-50">

    <?php if (isset($news)): ?>
      <?php foreach($news as $new):?>

        <div class="col-xs-12 all-complex-item zero-padding">
          <a data-toggle="modal" data-target=".modal_news" class="col-xs-4 ac-image zero-padding news-details" data-new-nid="<?php print $new['nid']; ?>" id="new-<?php print $new['nid']; ?>">
            <?php print $new['image']?>
          </a>
          <div class="col-xs-8 border news-content">
            <label><?php print $new['date']; ?></label>
            <h2><?php print $new['title']?></h2>
            <?php print $new['desc']; ?>
            <a class="news-details" id="new-<?php print $new['nid']; ?>" data-toggle="modal" data-target=".modal_news" data-new-nid="<?php print $new['nid']; ?>"><?php print t('Подробнее'); ?></a>
          </div>
        </div>

      <?php endforeach;?>
    <?php endif;?>

  </div>
</div>

<div class="modal fade modal_news" tabindex="-1" role="dialog" aria-labelledby="mySmallModalLabel" aria-hidden="true">

</div>