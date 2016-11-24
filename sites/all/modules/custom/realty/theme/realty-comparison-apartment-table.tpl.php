<?php if ($empty != TRUE): ?>
  <table class="comparison-table">
    <tr class="tr-fix">
      <td><?php print t('Квартира'); ?></td>
      <?php foreach($number_apartment as $ap):?>
        <td class="apt-<?php print $ap['nid']; ?>">
          <span class="anchor realty-appartment-info" data-toggle="modal" data-target=".flat_modal" data-id="<?php print $ap['nid'];?>" title="информация о квартире"><?php print $ap['number']; ?></span>

          <a title="удалить из сравнения" class="cross-table-block delete-apartment-comprassion" data-apartment-nid="<?php print $ap['nid']; ?>">
            <?php print $img_close; ?>
          </a>

        </td>
      <?php endforeach; ?>
    </tr>
    <tr>
      <td>Статус</td>
      <?php foreach($statuses as $key => $status): ?>
        <td class="apt-<?php print $key; ?>"><?php print $status; ?></td>
      <?php endforeach; ?>
    </tr>
    <tr>
      <td>Тип</td>
      <?php foreach($rooms as $key => $room): ?>
        <td class="apt-<?php print $key; ?>"><?php print $room; ?></td>
      <?php endforeach; ?>
    </tr>
    <tr>
      <td><?php print t('Площадь'); ?>, <span>м<sup>2</sup></span></td>
      <?php foreach($sq as $key => $s): ?>
        <td class="apt-<?php print $key; ?>"><?php print $s; ?></td>
      <?php endforeach; ?>
    </tr>
    <tr>
      <td><?php print t('Стоимость'); ?>, <span>руб</span></td>
      <?php foreach($coast as $key => $ap): ?>
        <td class="apt-<?php print $key; ?>"><?php print number_format($ap, 0, '', ' ' ); ?></td>
      <?php endforeach; ?>
    </tr>
    <tr>
      <td><?php print t('Жилой комплекс'); ?></td>
      <?php foreach($complex as $key => $ap):?>
        <td  class="anchor link apt-<?php print $key; ?>" onClick="location.href='<?php print $ap['link']?>' " title="перейти на страницу жк">
          <?php print $ap['complex'];?>
        </td>
      <?php endforeach; ?>
    </tr>
    <tr>
      <td><?php print t('застройщик'); ?></td>
      <?php foreach($developer as $key => $ap):?>
        <td class="anchor link apt-<?php print $key; ?>" onClick="location.href='<?php print $ap['link']?>' " title="перейти на страницу застройщика">
          <?php print $ap['developer'];?>
        </td>
      <?php endforeach; ?>
    </tr>
    <tr>
      <td><?php print t('срок сдачи'); ?></td>
      <?php foreach($deadline as $key => $ap):?>
        <td class="apt-<?php print $key; ?>"><?php print $ap; ?></td>
      <?php endforeach;?>
    </tr>
    <tr>
      <td><?php print t('материал стен'); ?></td>
      <?php foreach($masonry as $key => $ap):?>
        <td class="apt-<?php print $key; ?>"><?php print $ap; ?></td>
      <?php endforeach;?>
    </tr>
    <tr>
      <td><?php print t('Парковка'); ?></td>
      <?php foreach($parking as $key => $ap):?>
        <td class="apt-<?php print $key; ?>"><?php print $ap; ?></td>
      <?php endforeach;?>
    </tr>
    <tr>
      <td><?php print t('Балкон'); ?></td>
      <?php foreach($balcony as $key => $ap):?>
        <td class="apt-<?php print $key; ?>"><?php print $ap; ?></td>
      <?php endforeach;?>
    </tr>
    <tr>
      <td><?php print t('Этаж'); ?></td>
      <?php foreach($floor as $key => $ap):?>
        <td class="apt-<?php print $key; ?>"><?php print $ap; ?></td>
      <?php endforeach;?>
    </tr>
    <tr>
      <td><?php print t('Район'); ?></td>
      <?php foreach($area as $key => $ap):?>
        <td class="apt-<?php print $key; ?>"><?php print $ap; ?></td>
      <?php endforeach;?>
    </tr>
    <tr>
      <td><?php print t('Цена за м'); ?><sup>2</sup>, <span>руб</span></td>
      <?php foreach($price as $key => $ap):?>
        <td class="apt-<?php print $key; ?>"><?php print number_format($ap, 0, '', ' ' ); ?></td>
      <?php endforeach;?>
    </tr>

<!--    <tr>
      <td></td>
      <?php /*foreach($booking as $key => $val):*/?>
        <td class="apt-<?php /*print $key; */?>"><?php /*print $val; */?></td>
      <?php /*endforeach; */?>
    </tr>-->

  </table>
<?php else: ?>
  <div class="col-xs-12 empty-message">
    <h3>ни одна квартира не добавлена в сравнение</h3>
    <p>это можно сделать на странице квартиры</p>
    <?php print $search_link; ?>
  </div>
<?php endif; ?>
