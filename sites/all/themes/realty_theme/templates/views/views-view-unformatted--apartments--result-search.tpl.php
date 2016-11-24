<div class="col-xs-12 issue-header">
  <h2 class="col-xs-2 zero-padding">выдача<span>результатов</span></h2>
  <h1 class="col-xs-1 zero-padding">Найдено<br> квартир</h1>
  <h3 class="col-xs-6"><?php print $apt_count; ?></h3>
</div>

<div class="table-block">
  <table class="table issue-table display" id="example">
    <thead>
    <tr>
      <th id="bn">Квартира</th>
      <th data-sort="field_home_complex_target_id" data-order="ASC" class="sort sorting cursor-pointer mw70" style="min-width: 70px;"><?php print t('RC') ?></th>
      <th>Район</th>
      <th data-sort="field_complex_developer_tid" data-order="ASC" class="sort sorting cursor-pointer"><?php print t('Developer') ?></th>
      <th class="mw80">Адрес</th>
      <th data-sort="field_deadline_value" data-order="ASC" class="sort sorting cursor-pointer mw70" style="padding-bottom: 12px;">Срок<br>сдачи</th>
      <th data-sort="field_number_rooms_value" data-order="ASC" class="sort sorting cursor-pointer">Комн.&nbsp;&nbsp;</th>
      <th>Балкон&nbsp;&nbsp;</th>
      <th data-sort="field_apartment_floor_value" data-order="ASC" class="sort sorting cursor-pointer">  <?php print t('floor') . '&nbsp;&nbsp;&nbsp;&nbsp;' ?></th>
      <th data-sort="field_gross_area_value" data-order="ASC" class="sort sorting cursor-pointer mw60">S м<sup>2</sup>&nbsp;&nbsp;</th>
      <th data-sort="field_apartment_ceiling_height_value" data-order="ASC" class="sort sorting cursor-pointer mw70" style="padding-bottom: 12px;">Высота<br>потолка</th>
      <th data-sort="field_price_value" data-order="ASC" class="sort sorting cursor-pointer mw70" style="padding-bottom: 12px;">Цена, <br>р./м<sup>2</sup></th>
      <th data-sort="field_full_cost_value" data-order="ASC" class="sort sorting cursor-pointer"><?php print t('Coast');?>,&nbsp;руб.&nbsp;</th>
    </tr>
    </thead>
    <tbody>

    <?php if (!empty($view->result)):?>
      <?php foreach($apartments as $key=>$apartment) :?>
        <?php if ($apartment['status'] == 0):?>
          <tr title="Квартира забронирована" class="booking">
        <?php else: ?>
          <tr>
        <?php endif?>

            <td scope="row" class="no-hover anchor realty-appartment-info"  data-toggle="modal" data-target=".flat_modal" data-id="<?php print $apartment['nid']; ?>" data-toggle="modal" data-target=".flat_modal" >
              <a>
                <div class="flat-number">
                  <div class="circle">
                    <p>
                      <?php print $apartment['number']?>
                    </p>
                  </div>
                </div>
              </a>
            </td>
            <td class="anchor link realty-appartment-info" onClick='location.href="<?php print $apartment['complex_path']?>"' title="перейти на страницу жк">
              <?php print $apartment['complex']?>
            </td>
            <td class="anchor realty-appartment-info" data-toggle="modal" data-target=".flat_modal" data-id="<?php print $apartment['nid']; ?>">
              <?php print $apartment['area']?>
            </td>
            <td class="anchor link realty-appartment-info" onClick=location.href="<?php print $apartment['developer_path']?>" title="перейти на страницу застройщика">
              <?php print $apartment['developer']?>
            </td>
            <td class="anchor realty-appartment-info" data-toggle="modal" data-target=".flat_modal" data-id="<?php print $apartment['nid']; ?>">
              <?php print $apartment['address']?>
            </td>
            <td class="anchor realty-appartment-info" data-toggle="modal" data-target=".flat_modal" data-id="<?php print $apartment['nid']; ?>">
              <?php print $apartment['quarter'] . 'кв. ' . $apartment['year'] ?>
            </td>
            <td class="anchor realty-appartment-info" data-toggle="modal" data-target=".flat_modal" data-id="<?php print $apartment['nid']; ?>">
              <?php print $apartment['rooms']?>
            </td>
            <td class="anchor realty-appartment-info" data-toggle="modal" data-target=".flat_modal" data-id="<?php print $apartment['nid']; ?>">
              <?php if ($apartment['balkon']) : ?>
                <?php print "Б" ?>
              <?php elseif ($apartment['logia']) : ?>
                <?php print "Л" ?>
              <?php elseif ($apartment['balcony_loggia']) :?>
                <?php print 'Б+Л'?>
              <?php else: ?>
                <?php print "Нет" ?>
              <?php endif; ?>
            </td>
            <td class="anchor sort sorting realty-appartment-info" data-toggle="modal" data-target=".flat_modal" data-id="<?php print $apartment['nid']; ?>" data-sort="field_apartment_floor_value"  data-order="ASC">
              <?php print $apartment['floor'] . '/' . $apartment['home_floor'] ?>
            </td>
            <td class="anchor realty-appartment-info" data-toggle="modal" data-target=".flat_modal" data-id="<?php print $apartment['nid']; ?>">
              <?php print $apartment['sq']; ?>
            </td>
            <td class="anchor realty-appartment-info" data-toggle="modal" data-target=".flat_modal" data-id="<?php print $apartment['nid']; ?>">
              <?php print $apartment['ceiling']; ?>
            </td>
            <td class="anchor realty-appartment-info" data-toggle="modal" data-target=".flat_modal" data-id="<?php print $apartment['nid']; ?>">
              <?php print $apartment['price']?>
            </td>
            <td class="anchor realty-appartment-info" data-toggle="modal" data-target=".flat_modal" data-id="<?php print $apartment['nid']; ?>">
              <?php print $apartment['coast'];?>
            </td>
          </tr>

        <?php endforeach;?>
      <?php endif; ?>
    </tbody>
  </table>
</div>