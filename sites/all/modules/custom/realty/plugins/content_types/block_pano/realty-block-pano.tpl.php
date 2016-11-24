<div class="container-fluid container-fix" >
  <div class="row">
    <div class="col-xs-3 height fiftyminus zero-padding tours-title bbl" id="left-item">
      <a href="#">
        <div class="col-xs-12 index-item zero-padding">
          <h1><?php print t('3D tours')?></h1>
          <p><?php print t('Перейти на страницу всех 3D туров')?></p>
        </div>
      </a>
    </div>

    <div class="col-xs-9 col-xs-offset-3 big-height parent fotorama" data-width="100%" data-height="100%"  data-loop="true" data-shuffle="true" data-transition="slide" data-clicktransition="crossfade" data-arrows="true" data-click="false" data-swipe="false" data-nav="false">
      <?php foreach($complexes as $complex):?>
      <div class="big-height slider-info">
        <div class="col-xs-4 beige-block zero-padding">
          <div class="col-xs-12 half-item zero-padding">
            <?php if (!empty($complex['logo'])):?>
              <?php print $complex['logo']?>
            <?php endif?>
            <div class="gorizont-line">
            </div>
          </div>
          <div class="col-xs-12 second-quarter-item zero-padding display-table">
            <div class="vertical">
              <h2><?php print $complex['title']?></h2>
            </div>
          </div>
          <div class="col-xs-12 third-quarter-item zero-padding item-text-field display-table">
            <div class="vertical">
              <p>
                <?php print $complex['description']?>
              </p>
            </div>
          </div>
          <div class="col-xs-12 link-item zero-padding display-table">
            <div class="vertical">
              <?php print $complex['details'] ?>
            </div>
          </div>
        </div>
        <div class="col-xs-8 big-height zero-padding">
          <?php print render($complex['image'])?>
        </div>
      </div>
      <?php endforeach;?>
    </div>
  </div>
</div>