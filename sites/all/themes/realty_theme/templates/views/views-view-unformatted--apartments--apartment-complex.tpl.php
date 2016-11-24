<div class="container fin">
  <div class="col-xs-12">
    <div class="col-xs-3 zero-padding new-filter-container">
      <h3>Квартир в<br>этом комплексе<span><?php print $apartment_count; ?></span></h3>
    </div>
    <table class="table issue-table display" id="example" style="padding: 10px;">

      <thead class="tableFloatingHeaderOriginal">
      <tr>
        <th id="bn">
          <?php print t('Apartment')?>
        </th>
        <th>
          <?php print t('Address');?>
        </th>
        <th data-sort="field_section_value" data-order="ASC" class="sort sorting cursor-pointer">
          <?php print t('Section');?>
        </th>
        <th data-sort="field_number_rooms_value" data-order="ASC" class="sort sorting cursor-pointer">
          <?php print t('Rooms') . '&nbsp&nbsp'?>
        </th>
        <th>Балкон&nbsp&nbsp</th>
        <th data-sort="field_apartment_floor_value"  data-order="ASC" class="sort sorting cursor-pointer">
          <?php print t('floor') . '&nbsp&nbsp';?>
        </th>
        <th data-sort="field_gross_area_value" data-order="ASC" class="sort sorting cursor-pointer">
          S м<sup>2</sup>
        </th>
        <th style="min-width: 58px;" data-sort="field_price_value" data-order="ASC" class="sort sorting cursor-pointer">
          Цена, &nbsp;руб./м<sup>2</sup>&nbsp;&nbsp;
        </th>
        <th data-sort="field_full_cost_value" data-order="ASC" class="sort sorting cursor-pointer">
          <?php print t('Coast');?>,&nbsp;руб.
        </th>
      </tr>
      </thead>

      <thead class="tableFloatingHeader" style="display: none;">
      <tr>
        <th id="bn">
          <?php print t('Apartment')?>
        </th>
        <th>
          <?php print t('Address');?>
        </th>
        <th>
          <?php print t('Section');?>
        </th>
        <th class="sorting-up">
          <?php print t('Rooms') . '&nbsp&nbsp'?>
        </th>
        <th>Балкон&nbsp&nbsp</th>
        <th class="sorting-down ">
          <?php print t('floor') . '&nbsp&nbsp';?>
        </th>
        <th>
          <?php print t('SQ');?>
        </th>
        <th style="min-width: 58px;">
          <?php print t('Price')?> м<sup>2</sup>&nbsp;
        </th>
        <th>
          <?php print t('Coast');?>&nbsp;
        </th>
      </tr>
      </thead>

      <tbody>
      <?php if($apartments):?>
        <?php foreach($apartments as $apartment):?>
          <?php if ($apartment['status'] == 0):?>
            <tr title="Квартира забронирована" class="booking">
          <?php else: ?>
            <tr>
          <?php endif?>

          <td scope="row" class="no-hover realty-appartment-info anchor" data-toggle="modal" data-target=".flat_modal" data-id="<?php print $apartment['nid']; ?>" data-toggle="modal" data-target=".flat_modal">
            <a title="Посмотреть квартиру">
              <div class="flat-number">
                <div class="circle">
                  <?php print $apartment['number']?>
                </div>
              </div>
            </a>
          </td>
          <td class="anchor realty-appartment-info" data-toggle="modal" data-target=".flat_modal" data-id="<?php print $apartment['nid']; ?>">
            <?php print $apartment['address']?>
          </td>
          <td class="anchor realty-appartment-info" data-toggle="modal" data-target=".flat_modal" data-id="<?php print $apartment['nid']; ?>">
            <?php print $apartment['section']?>
          </td>
          <td class="anchor realty-appartment-info" data-toggle="modal" data-target=".flat_modal" data-id="<?php print $apartment['nid']; ?>">
            <?php print $apartment['room']?>
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
          <td class="anchor realty-appartment-info" data-toggle="modal" data-target=".flat_modal" data-id="<?php print $apartment['nid']; ?>">
            <?php print $apartment['floor']?>/<?php print $apartment['home_floor']?>
          </td>
          <td class="anchor realty-appartment-info" data-toggle="modal" data-target=".flat_modal" data-id="<?php print $apartment['nid']; ?>">
            <?php print $apartment['sq']?>
          </td>
          <td class="anchor realty-appartment-info" data-toggle="modal" data-target=".flat_modal" data-id="<?php print $apartment['nid']; ?>">
            <?php print $apartment['price'];?>
          </td>
          <td class="anchor realty-appartment-info" data-toggle="modal" data-target=".flat_modal" data-id="<?php print $apartment['nid']; ?>">
            <?php print $apartment['coast'];?>
          </td>
          </tr>
        <?php endforeach;?>
      <?php endif;?>

      </tbody>
    </table>
  </div>
</div>