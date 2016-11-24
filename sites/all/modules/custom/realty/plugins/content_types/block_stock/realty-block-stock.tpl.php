<div class="container-fluid container-fix" >
  <div class="row bb margin-top-2">
    <div class="col-xs-6 zero-padding">

      <div class="col-xs-12 height fifty zero-padding">
        <div class="col-xs-6 zero-padding stock-left ">
          <?php if($stock[0]):?>
            <?php print $stock[0]['image']?>
          <?php endif?>
        </div>

          <div class="col-xs-6 zero-padding stock-right beigh">
            <div class="col-xs-12 stock-header zero-padding display-table">
              <div class="vertical">
                <p>
                  <?php print $stock[0]['developer']; ?>
                </p>
              </div>
            </div>
            <div class="col-xs-12 stock-title zero-padding display-table">
              <div class="vertical">
                <h2>
                  <?php if(isset($stock[0])):?>
                    <?php print $stock[0]['title']?>
                  <?php endif?>
                </h2>
              </div>
            </div>
            <div class="col-xs-12 stock-text zero-padding display-table">
              <div class="vertical">
                <p>
                  <?php if(isset($stock[0])):?>
                    <?php print $stock[0]['description']?>
                  <?php endif?>
                </p>
              </div>
            </div>
            <div class="col-xs-12 stock-link zero-padding display-table">
              <div class="vertical">
                <?php if(isset($stock[0])):?>
                  <?php print $stock[0]['details']?>
                <?php endif?>
              </div>
            </div>
            <div class="arrow-left">
            </div>
          </div>

      </div>

      <div class="col-xs-12 height fifty zero-padding ">
        <div class="col-xs-6 zero-padding stock-left beigh">
          <div class="col-xs-12 stock-header zero-padding display-table">
            <div class="vertical">
              <p>
                <?php print $stock[1]['developer']; ?>
              </p>
            </div>
          </div>
          <div class="col-xs-12 stock-title zero-padding display-table">
            <div class="vertical">
              <h2>
                <?php if(isset($stock[1])):?>
                  <?php print $stock[1]['title']?>
                <?php endif?>
              </h2>
            </div>
          </div>
          <div class="col-xs-12 stock-text zero-padding display-table">
            <div class="vertical">
              <p>
                <?php if(isset($stock[1])):?>
                  <?php print $stock[1]['description']?>
                <?php endif?>
              </p>
            </div>
          </div>
          <div class="col-xs-12 stock-link zero-padding display-table">
            <div class="vertical">
              <?php if(isset($stock[1])):?>
                <?php print $stock[1]['details']?>
              <?php endif?>
            </div>
          </div>
          <div class="arrow-right">
          </div>
        </div>

          <div class="col-xs-6 zero-padding stock-right">
            <?php if(isset($stock[1])):?>
              <?php print $stock[1]['image']?>
            <?php endif?>
          </div>

      </div>

    </div>

    <div class="col-xs-6 big-height fifty zero-padding big-stock">
      <?php if($priority_stock):?>
        <?php print render($priority_stock['image'])?>
      <?php endif?>
      <div class="col-xs-6 quarter zero-padding">
        <div class="col-xs-12 stock-header zero-padding display-table">
          <div class="vertical">
            <p>
              <?php print $priority_stock['developer']; ?>
            </p>
          </div>
        </div>
        <div class="col-xs-12 stock-title zero-padding display-table">
          <div class="vertical">
            <h2>
              <?php if($priority_stock):?>
                <?php print render($priority_stock['title'])?>
              <?php endif?>
            </h2>
          </div>
        </div>
        <div class="col-xs-12 stock-text zero-padding display-table">
          <div class="vertical">
            <p>
              <?php if($priority_stock):?>
                <?php print $priority_stock['description']?>
              <?php endif?>
            </p>
          </div>
        </div>
        <div class="col-xs-12 stock-link zero-padding display-table">
          <div class="vertical">
            <?php if($priority_stock):?>
              <?php print $priority_stock['details']?>
            <?php endif?>
          </div>
        </div>
        <div class="bigstock-arrow">
        </div>
      </div>
      <div class="col-xs-6 col-xs-offset-6 quarter-top zero-padding" id="left-item">
        <a href="<?php print $all_stock?>">
          <div class="col-xs-12 index-item zero-padding">
            <h2>
              Акции/новости
            </h2>
            <p>
              <?php print t('Прейти к списку всех акций')?>
            </p>
          </div>
        </a>
      </div>
      <div id="mortgage">
      </div>
    </div>
  </div>
</div>