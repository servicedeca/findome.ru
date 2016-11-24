<div class="col-xs-10 col-xs-offset-1 gallery-body zero-padding">
  <?php if (isset($albums)):?>
    <?php foreach($albums as $i => $album):?>
      <div class="col-xs-4 gallery-item may-album-<?php print $i?> visual-item developer-visual-item">

        <?php print $album['image_album']?>
        <?php foreach($album['photos'] as $key => $photo):?>
          <?php if ($key != 0) print $photo;?>
        <?php endforeach;?>
        <p><?php print $album['title']?></p>

      </div>
    <?php endforeach;?>
  <?php endif;?>
  <?php foreach ($caps as $cap): ?>
    <?php print $cap; ?>
  <?php endforeach; ?>
</div>