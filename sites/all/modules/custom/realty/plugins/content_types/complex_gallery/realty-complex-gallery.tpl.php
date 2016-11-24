<div class="container-fluid container-fix about-header about-header-bigger" id="parallax" data-speed="6" data-type="background" style="background-image: url(<?php print $background; ?>); background-position: 50% -26.5px;">
  <div class="about-header-layer">
    <div class="col-xs-12 zero-padding complex-line">
    </div>
    <div class="ap-header-layer-top">
    </div>
    <div class="container fin about-overflow">
      <ul class="col-xs-12 zero-padding text-center ap-complex-fix" role="tablist">

        <?php if (isset($visualisation)): ?>
          <li role="presentation" class="active br">
            <a href="#diary"  role="tab" data-toggle="tab" aria-controls="home" aria-expanded="true">
              Дневники стройки
              <?php print $img_hover; ?>
            </a>
          </li>
        <?php endif; ?>

        <?php if (isset($photos)): ?>
          <li role="presentation" class="<?php !isset($visualisation) ? print 'active ' : print 'br'; ?>">
            <a href="#visual" role="tab" data-toggle="tab" aria-controls="profile" aria-expanded="false">
              Визуализации
              <?php print $img_hover; ?>
            </a>
          </li>
        <?php endif; ?>
        <?php if (isset($video)): ?>
          <li role="presentation" class="<?php !isset($visualisation) && !isset($video) ? print 'active ' : print 'br'; ?>br">
            <a href="#video" role="tab" data-toggle="tab" aria-controls="profile" aria-expanded="false">
              Видео
              <?php print $img_hover; ?></a>
          </li>
        <?php endif; ?>
      </ul>

      <div class="tab-content">

        <?php if (isset($photos)): ?>
          <div class="col-xs-12 tab-pane fade active in modal-info-text" aria-labelledby="home-tab" id="diary" style="height: 520px; overflow: auto;">
            <?php print $photos; ?>
          </div>
        <?php endif; ?>

        <?php if (isset($visualisation)): ?>
          <div role="tab-panel" class="col-xs-12 tab-pane fade" aria-labelledby="home-tab" id="visual">
            <?php print $visualisation; ?>
          </div>
        <?php endif; ?>

        <?php if(isset($video)):?>
          <div class="col-xs-12 tab-pane fade <?php !isset($visualisation) && !isset($video) ? print 'active in' : print ''; ?>" id="video" role="tabpanel" aria-labelledby="profile-tab">
            <?php print $video; ?>
          </div>
        <?php endif; ?>
      </div>
    </div>
  </div>
</div>

<div class="modal modal_video" tabindex="-1" role="dialog" aria-labelledby="mySmallModalLabel" aria-hidden="true">
  <div class="container container-modal-city modal-video-bg zero-padding">
    <div class="col-xs-12 list-modal-video">
      <button type="button" class="close close-modal video-stop" data-dismiss="modal" aria-hidden="true">
        <?php print $img_close; ?>
      </button>

      <div id="bs">

      </div>

    </div>
  </div>
</div>