<div class="container-fluid container-fix all-complex-block">
  <div class="ap-header-layer-top h15">
  </div>

  <div class="container fin mb-50">
    <?php if (isset($stocks)): ?>
      <?php foreach($stocks as $stock):?>
        <div class="col-xs-12 all-complex-item zero-padding">
          <a data-toggle="modal" data-target=".modal_stock" class="col-xs-4 ac-image zero-padding stock-details modal-stock-<?php print $stock['nid']; ?>" data-stock-nid="<?php print $stock['nid']; ?>">
            <?php print $stock['image']?>
          </a>
          <div class="col-xs-8 border news-content">
            <label></label>
            <h2>
              <?php print $stock['title']?>
            </h2>
            <?php print $stock['description']?>

            <?php print $stock['complex']; ?>
            <a class="slink_m stock-details" id="modal-stock-<?php print $stock['nid']; ?>" data-toggle="modal" data-target=".modal_stock" data-stock-nid="<?php print $stock['nid']; ?>"><?php print t('Подробнее'); ?></a>
          </div>
        </div>
    <?php endforeach; ?>
    <?php endif; ?>
  </div>
</div>

<div class="modal fade modal_stock" tabindex="-1" role="dialog" aria-labelledby="mySmallModalLabel" aria-hidden="true">

</div>
