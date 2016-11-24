<div class="container-fluid container-fix about-header about-header-bigger" id="parallax" data-speed="3" data-type="background" style="background-image: url(<?php $background ? print $background : 0 ?>);">
  <div class="about-header-layer">
    <div class="col-xs-12 zero-padding complex-line">
    </div>
    <div class="ap-header-layer-top">
    </div>
    <div class="container fin about-overflow">
      <ul class="col-xs-12 zero-padding text-center ap-complex-fix" role="tablist">
        <li role="presentation" class="active br">
          <a href="#now"  role="tab" data-toggle="tab" aria-controls="home" aria-expanded="true">
            Текущие
            <?php print $img_hover; ?>
          </a>
        </li>
      </ul>

      <div class="tab-content">
        <div role="tabpanel" class="tab-pane fade active in modal-info-text" aria-labelledby="home-tab" id="now">
          <div class="col-xs-9 zero-padding dev-map">
            <div id="map" style="width:100%; height:100%;">
              <?php print $map;?>
            </div>
          </div>
          <div class="col-xs-3 devs-complex">
            <div class="vertical">
              <?php if(isset($logos)): ?>
                <?php foreach ($logos as $logo): ?>
                  <?php print $logo; ?>
                <?php endforeach; ?>
              <?php endif; ?>
            </div>
          </div>
        </div>
      </div>
    </div>
  </div>
</div>