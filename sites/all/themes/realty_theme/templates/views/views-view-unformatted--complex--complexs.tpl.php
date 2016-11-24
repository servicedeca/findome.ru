<div class="container-fluid container-fix all-complex-block">
  <div class="ap-header-layer-top h15">
  </div>
  <div class="container fin mb-50">

    <?php foreach($complexes as $value):?>
      <div class="col-xs-12 all-complex-item zero-padding">
        <a href="<?php print $value['complex_link'];?>" class="col-xs-4 ac-image zero-padding">
          <?php print render($value['photo']); ?>
        </a>
        <a href="<?php print $value['complex_link'];?>" class="col-xs-4 ac-logo zero-padding">
          <?php print render($value['logo']); ?>
        </a>

        <div class="all-complex-rating" onClick="location.href='/complexes/<?php print $value['complex_id']; ?>/rating' ">
          <div class="progress-rating progress-rating-all">
            <div style="width:<?php print $value['rating']; ?>%"></div>
            <?php print $img_starz; ?>
            <p><span><?php print $value['rating']; ?> </span>/ 100</p>
          </div>
        </div>

        <div class="col-xs-4 ac-content">
          <div class="col-xs-9 zero-padding">
            <h2><?php print $value['name']; ?></h2>

            <label>Застройщик</label>
            <p><?php print $value['developer'];?></p>

            <label>Срок сдачи</label>
            <p><?php print $value['quarter'];?> квартал <?php print $value['year'];?> года</p>

            <label>Квартир в продаже</label>
            <p>
              <?php print $value['apartments']; ?>
            </p>

            <label>СРЕДНЯЯ ЦЕНА М<sup>2</sup> В ПРОДАЖЕ, РУБ.</label>
            <p><span><?php print $value['price'];?></span></p>

          </div>
          <div class="col-xs-3">
            <div class="ac-content-link">
              <a href="<?php print $value['complex_link']; ?>">Перейти на страницу комплекса
                <?php print $img_arrow; ?>
              </a>
            </div>
          </div>
        </div>
      </div>
    <?php endforeach;?>

  </div>
</div>