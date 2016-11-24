<div class="new-complex-bg">

  <div class="container-fluid container-fix about-header" data-speed="3" data-type="background" style="background-image: url(<?php print $background; ?>);">
    <div class="newcomplex-layer">
      <div class="container fin">
        <div class="col-xs-4 zero-padding rating-stat">
          <h2>Рейтинг</h2>

          <p><?php print $complex_rating; ?> <span>/ 100</span></p>

          <div class="rating-wrapper rating-inline">
            <div style="width:<?php print $complex_rating; ?>%;" class="current-rating">
            </div>
          </div>

        </div>
        <div class="col-xs-8 rating-points">
          <div class="col-xs-10" style="padding-left:270px;padding-top: 10px;">
            <p>Народный рейтинг</p>
            <p>Финансирование</p>
            <p>Договор</p>
            <p>Инфраструктура</p>
            <p>Дом/двор</p>
            <p>Информационная открытость</p>
          </div>
          <div class="col-xs-2 text-right">
            <label><?php print $peoples_rating; ?><span> / 10</span></label>
            <label><?php print $finance_rating; ?><span> / 20</span></label>
            <label><?php print $contract_rating; ?><span> / 10</span></label>
            <label><?php print $infrastruct_rating; ?><span> / 20</span></label>
            <label><?php print $yard_rating; ?><span> / 20</span></label>
            <label><?php print $info_rating; ?><span> / 20</span></label>
          </div>
        </div>
      </div>
    </div>
  </div>

  <div class="about-c-big-line">
  </div>

  <div class="container fin">
    <div class="col-xs-12 container-rating">
      <div class="col-xs-6 h70">
        <h3>Народный рейтинг</h3>
      </div>
      <div class="col-xs-6 h70 text-right post-h">
        <label><?php print $peoples_rating; ?><span style="color:#b3b3b3; font-size:35px; margin-right:0px;">&nbsp;/&nbsp;10</span></label>
      </div>
    </div>
  </div>

  <div class="about-c-big-line">
  </div>

  <div class="container fin">
    <div class="col-xs-12 container-rating">
      <div class="col-xs-6 h70">
        <p>Отзывы о застройщике</p>
        <label></label>
      </div>
      <div class="col-xs-6 h70 text-right post">
        <?php print $review_developer_rating_question; ?>
        <label><?php print $review_developer_rating ?></label>
      </div>
    </div>
  </div>

  <div class="about-c-line">
  </div>

  <div class="container fin">
    <div class="col-xs-12 container-rating">
      <div class="col-xs-6 h70">
        <p>Отзывы собственников квартир в данном ЖК</p>
        <label></label>
      </div>
      <div class="col-xs-6 h70 text-right post">
        <?php print $review_complex_rating_question; ?>
        <label><?php print $review_complex_rating ?></label>
      </div>
    </div>
  </div>

  <div class="about-c-line">
  </div>

  <div class="about-c-big-line">
  </div>

  <div class="container fin">
    <div class="col-xs-12 container-rating">
      <div class="col-xs-6 h70">
        <h3>Финансирование</h3>
      </div>
      <div class="col-xs-6 h70 text-right post-h">
        <label><?php print $finance_rating ?><span style="color:#b3b3b3; font-size:35px; margin-right:0px;">&nbsp;/&nbsp;20</span></label>
      </div>
    </div>
  </div>

  <div class="about-c-big-line">
  </div>

  <div class="container fin">
    <div class="col-xs-12 container-rating">
      <div class="col-xs-6 h70">
        <p>Собственные средства</p>
        <label><?php print $finance_rating_own['text']; ?></label>
      </div>
      <div class="col-xs-6 h70 text-right post">
        <?php print $finance_rating_own_question; ?>
        <label><?php print $finance_rating_own['value']; ?></label>
      </div>
    </div>
  </div>

  <div class="about-c-line">
  </div>

  <div class="container fin">
    <div class="col-xs-12 container-rating">
      <div class="col-xs-6 h70">
        <p>Заемные средства</p>
        <label><?php print $finance_rating_cre['text']; ?></label>
      </div>
      <div class="col-xs-6 h70 text-right post">
        <?php print $finance_rating_cre_question; ?>
        <label><?php print $finance_rating_cre['value']; ?></label>
      </div>
    </div>
  </div>

  <div class="about-c-line">
  </div>

  <div class="container fin">
    <div class="col-xs-12 container-rating">
      <div class="col-xs-6 h70">
        <p>Средства участников долевого строительства в общей структуре</p>
        <label><?php print $finance_rating_par['text']; ?></label>
      </div>
      <div class="col-xs-6 h70 text-right post">
        <?php print $finance_rating_par_question; ?>
        <label><?php print $finance_rating_par['value']; ?></label>
      </div>
    </div>
  </div>

  <div class="about-c-line">
  </div>

  <div class="about-c-big-line">
  </div>

  <div class="container fin">
    <div class="col-xs-12 container-rating">
      <div class="col-xs-6 h70">
        <h3>Договор</h3>
      </div>
      <div class="col-xs-6 h70 text-right post-h">
        <label><?php print $contract_rating ?><span style="color:#b3b3b3; font-size:35px; margin-right:0px;">&nbsp;/&nbsp;10</span></label>
      </div>
    </div>
  </div>

  <div class="about-c-big-line">
  </div>

    <div class="container fin">
      <div class="col-xs-12 container-rating">
        <div class="col-xs-6 h70">
          <p>Тип договора</p>
          <label><?php print $contr_rating_type['text']; ?></label>
        </div>
        <div class="col-xs-6 h70 text-right post">
          <?php print $contr_rating_type_question; ?>
          <label><?php print $contr_rating_type['value']; ?></label>
        </div>
      </div>
    </div>

  <div class="about-c-line">
  </div>

  <div class="about-c-big-line">
  </div>

  <div class="container fin">
    <div class="col-xs-12 container-rating">
      <div class="col-xs-6 h70">
        <h3>Инфраструктура</h3>
      </div>
      <div class="col-xs-6 h70 text-right post-h">
        <label><?php print $infrastruct_rating; ?><span style="color:#b3b3b3; font-size:35px; margin-right:0px;">&nbsp;/&nbsp;20</span></label>
      </div>
    </div>
  </div>

  <div class="about-c-big-line">
  </div>

  <?php foreach ($infra_rating as $rating): ?>

  <div class="container fin">
    <div class="col-xs-12 container-rating">
      <div class="col-xs-6 h70">
        <p><?php print $rating['title']; ?></p>
        <label><?php print $rating['text']; ?></label>
      </div>
      <div class="col-xs-6 h70 text-right post">
        <?php print $rating['question']; ?>
        <label><?php print $rating['value']; ?></label>
      </div>
    </div>
  </div>

  <div class="about-c-line">
  </div>

  <?php endforeach; ?>

  <div class="about-c-big-line">
  </div>

  <div class="container fin">
    <div class="col-xs-12 container-rating">
      <div class="col-xs-6 h70">
        <h3>Дом/Двор</h3>
      </div>
      <div class="col-xs-6 h70 text-right post-h">
        <label><?php print $yard_rating ?><span style="color:#b3b3b3; font-size:35px; margin-right:0px;">&nbsp;/&nbsp;20</span></label>
      </div>
    </div>
  </div>

  <div class="about-c-big-line">
  </div>

  <?php foreach ($yard_rating_all as $rating): ?>

    <div class="container fin">
      <div class="col-xs-12 container-rating">
        <div class="col-xs-6 h70">
          <p><?php print $rating['title']; ?></p>
          <label><?php print $rating['text']; ?></label>
        </div>
        <div class="col-xs-6 h70 text-right post">
          <?php print $rating['question']; ?>
          <label><?php print $rating['value']; ?></label>
        </div>
      </div>
    </div>

    <div class="about-c-line">
    </div>

  <?php endforeach; ?>

  <div class="about-c-big-line">
  </div>

  <div class="container fin">
    <div class="col-xs-12 container-rating">
      <div class="col-xs-6 h70">
        <h3>Информационная открытость</h3>
      </div>
      <div class="col-xs-6 h70 text-right post-h">
        <label><?php print $info_rating ?><span style="color:#b3b3b3; font-size:35px; margin-right:0px;">&nbsp;/&nbsp;20</span></label>
      </div>
    </div>
  </div>

  <div class="about-c-big-line">
  </div>

  <?php foreach ($info_rating_all as $rating): ?>

    <div class="container fin">
      <div class="col-xs-12 container-rating">
        <div class="col-xs-6 h70">
          <p><?php print $rating['title']; ?></p>
          <label><?php print $rating['text']; ?></label>
        </div>
        <div class="col-xs-6 h70 text-right post">
          <?php print $rating['question']; ?>
          <label><?php print $rating['value']; ?></label>
        </div>
      </div>
    </div>

    <div class="about-c-line">
    </div>

  <?php endforeach; ?>

</div>