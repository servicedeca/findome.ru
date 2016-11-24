<div class="col-xs-10 col-xs-offset-1 gallery-body zero-padding visual-album">
  <?php if (isset($photos)):?>
    <?php foreach ($photos as $photo):?>
      <div class="col-xs-4 gallery-item visual-item">
        <?php print $photo;?>
      </div>
    <?php endforeach;?>
  <?php endif;?>
  <?php foreach ($caps as $cap): ?>
    <?php print $cap; ?>
  <?php endforeach; ?>
</div>