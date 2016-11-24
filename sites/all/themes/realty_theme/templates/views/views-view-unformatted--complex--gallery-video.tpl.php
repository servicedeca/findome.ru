<div class="col-xs-10 col-xs-offset-1 gallery-body zero-padding video-album">
  <?php foreach ($videos as $video): ?>
  <div class="col-xs-4 gallery-item video-item" data-video-id="<?php print $video; ?>" data-toggle="modal" data-target=".modal_video">
    <div class="frame-cap"></div>
    <div id="as">
      <iframe class="video-frame-modal" src="https://www.youtube.com/embed/<?php print $video; ?>?rel=0&amp;controls=0&amp;showinfo=0" frameborder="0" allowfullscreen=""></iframe>
    </div>

  </div>
  <?php endforeach; ?>
  <?php foreach ($caps as $cap): ?>
    <?php print $cap; ?>
  <?php endforeach; ?>
</div>