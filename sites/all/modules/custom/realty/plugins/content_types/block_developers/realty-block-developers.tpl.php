<div class="container-fluid container-fix">
  <div class="row margin-top-2">
    <div class="col-xs-3 height fiftyminus zero-padding ">
      <a href="<?php print $all_developers ?>">
        <div class="col-xs-12 index-item zero-padding">
          <h2>
            <?php print t('Developers')?>
          </h2>
          <p>
            <?php print t('Перейти к списку всех застройщиков');?>
          </p>
        </div>
      </a>
    </div>

    <div class="col-xs-9 fiftyplus height zero-padding">
      <?php if($developers):?>
        <?php foreach($developers as $developer):?>
          <a href="<?php print $developer['path']?>">
            <?php if($developer['path'] != '#href'): ?>
              <div class="col-xs-2 z-item">
            <?php else: ?>
                <div class="col-xs-2 z-item cursor-normal">
            <?php endif; ?>
              <?php print $developer['logo']?>
            </div>
          </a>
        <?php endforeach?>
      <?php endif?>
      <div id="stock">
      </div>
    </div>

  </div>
</div>