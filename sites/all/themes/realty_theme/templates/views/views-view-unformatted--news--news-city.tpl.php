<div class="col-xs-9 fiftyplus height zero-padding">
  <?php if(!empty($news)):?>
    <?php foreach($news as $new):?>
      <div class="col-xs-4 zero-padding newsitem">
        <div class="col-xs-12 stock-header zero-padding display-table">
          <div class="vertical">
            <p> <?php print $new['date']?></p>
          </div>
        </div>
        <div class="col-xs-12 stock-title zero-padding display-table">
          <div class="vertical">
            <h2><?php print $new['title']?></h2>
          </div>
        </div>
        <div class="col-xs-12 stock-text zero-padding display-table">
          <div class="vertical">
            <p><?php print $new['description']?></p>
          </div>
        </div>
        <div class="col-xs-12 stock-link zero-padding display-table">
          <div class="vertical">
            <?php print $new['details']?>
          </div>
        </div>
      </div>
    <?php endforeach?>
  <?php endif?>
</div>
