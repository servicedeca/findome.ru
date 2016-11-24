<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8" />
  <title>PDF квартиры</title>
  <style>
    <?php print file_get_contents(REALTY_FRONT_THEME_PATH . '/css/style_pdf.css');?>
  </style>
</head>

<body id="pdf-page">
<div class="a4">
<div class="cxs-12 pdf-head">
  <h1>Квартира<span>
      <?php print $number; ?>
  </span></h1>
  <?php print $logo; ?>
</div>
<div class="cxs-8 pdf-plane-block">
  <label>планировка</label>
  <?php print $plan; ?>
</div>
<div class="cxs-4 pdf-plane-info">
  <label>параметры</label>
  <div class="col-xs-12 about-inner-item">
    <lebel>Общая площадь, м<sup>2</sup></lebel>
    <h1><?php print $sq; ?></h1>
  </div>
  <div class="col-xs-12 about-inner-item">
    <lebel>Стоимость, руб.</lebel>
    <h1><?php print $coast; ?></h1>
  </div>
  <div class="col-xs-12 about-inner-item">
    <lebel>Тип</lebel>
    <h2><?php print $rooms; ?></h2>
  </div>
  <div class="col-xs-12 about-inner-item">
    <lebel>Жилой комплекс</lebel>
    <h2><?php print $complex; ?></h2>
  </div>
  <div class="col-xs-12 about-inner-item">
    <lebel>Адрес</lebel>
    <h2><?php print $home_address; ?></h2>
  </div>
  <div class="col-xs-12 about-inner-item">
    <lebel>Секция</lebel>
    <h2><?php print $section; ?></h2>
  </div>
  <div class="col-xs-12 about-inner-item">
    <lebel>Этаж</lebel>
    <h2><?php print $floor; ?></h2>
  </div>
  <div class="col-xs-12 about-inner-item">
    <lebel>Цена за м<sup>2</sup>, руб</lebel>
    <h2><?php print $price; ?></h2>
  </div>
  <div class="col-xs-12 about-inner-item">
    <lebel>Срок сдачи</lebel>
    <h2><?php print $deadline; ?></h2>
  </div>
  <div class="col-xs-12 about-inner-item">
    <lebel>Жилая площадь, м<sup>2</sup></lebel>
    <h2><?php print $living_sq; ?></h2>
  </div>
  <div class="col-xs-12 about-inner-item">
    <lebel>застройщик</lebel>
    <h2><?php print $developer; ?></h2>
  </div>
</div>

<div class="pdf-footer">
  <p>
    Материалы предоставлены в информационных целях. Все права на изображения и тексты принадлежат их правообладателям.
  </p>
  <p>
    © 2015 FINDOME.RU При использовании материалов гиперссылка на findome.ru обязательна.
  </p>
</div>
</div>



</body>
</html>