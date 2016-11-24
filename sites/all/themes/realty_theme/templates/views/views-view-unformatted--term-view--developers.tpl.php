<div class="container fin">
  <div class="col-xs-6 header-menu">
    <h1>застройщики<br><span>новосибирска</span></h1>
  </div>
  <div class="col-xs-6 fifty zero-padding header-block">
    <a href="/node/4629" class="header-quest scrollp">
      <?php print $img_quest; ?>
      <h2>Как выбрать застройщика?</h2>
      <p>5 советов по выбору<br>надежного застройщика </p>
    </a>
  </div>
</div>

<div class="container-fluid container-fix all-complex-block">
  <div class="ap-header-layer-top h15">
  </div>
  <div class="container fin mb-50">

    <?php foreach($developers as $value):?>

      <div class="col-xs-12 all-complex-item zero-padding">
        <a href="<?php print $value['developer_link'];?>" class="col-xs-4 ac-image zero-padding">
          <?php if (isset($value['photo'])): ?>
            <?php print $value['photo']; ?>
          <?php endif; ?>
        </a>
        <a href="<?php print $value['developer_link'];?>" class="col-xs-4 ac-logo zero-padding">
          <?php if (isset($value['logo'])): ?>
            <?php print render($value['logo']); ?>
          <?php endif; ?>
        </a>
        <div class="col-xs-4 ac-content">
          <div class="col-xs-9 zero-padding">
            <h2><?php print $value['name']; ?></h2>

            <?php if (isset($value['complexes'])): ?>
              <label>Новостройки</label>
              <?php foreach($value['complexes'] as $key => $val): ?>
                <?php if ($key < 2): ?>
                  <p><?php print render($val['complex']); ?></p>
                <?php else: ?>
                  <p>и еще <span><?php print $value['complex_count']; ?></span> объектов</p><?php break; ?>
                <?php endif; ?>
              <?php endforeach;?>
            <?php endif; ?>

            <?php if (isset($value['apt_count'])): ?>
              <label>Квартир в продаже</label>
              <p><span><?php print $value['apt_count']; ?></span></p>
            <?php endif; ?>

            <?php if (isset($value['price_from'])): ?>
              <label>СРЕДНЯЯ ЦЕНА М<sup>2</sup> В ПРОДАЖЕ, РУБ.</label>
              <p><span><?php print $value['price_from']; ?></span></p>
            <?php endif; ?>

          </div>
          <div class="col-xs-3">
            <div class="ac-content-link">
              <a href="<?php print $value['developer_link'];?>">Перейти на страницу застройщика
                <?php print $img_arrow; ?>
              </a>
            </div>
          </div>
        </div>
      </div>

    <?php endforeach; ?>

  </div>
</div>