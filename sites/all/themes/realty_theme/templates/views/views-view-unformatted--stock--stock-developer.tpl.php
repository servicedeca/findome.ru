<?php if(isset($stocks)):?>
  <?php foreach($stocks as $key => $stock):?>

    <div data-toggle="modal" data-target=".modal_stock" data-stock-nid="<?php print $stock['nid']; ?>" class="modal-stock-<?php print $stock['nid']; ?> col-xs-12 zero-padding doc-item cursor-pointer stock-details">
      <div class="col-xs-1 zero-padding">
        <?php print $img_stock; ?>
        <div class="blue-print">
        </div>
      </div>
      <div class="col-xs-11 col-xs-ofset-1 stock-download">
        <h2><?php print $stock['title']?></h2>
      </div>
    </div>

  <?php endforeach;?>
<?php endif;?>