<?php if ($empty != TRUE): ?>
  <table class="book-table">
    <tr>

      <th>№ квартиры</th>
      <th>№ брони</th>
      <th>подтверждение сделки</th>
      <th></th>
      <th>статус</th>

    </tr>
    <?php foreach($bookings as $book): ?>
      <tr>
        <td class="anchor realty-appartment-info" data-toggle="modal" data-target=".flat_modal" data-id="<?php print $book['app_nid']; ?>"" title="перейти на страницу квартиры">
        <?php print $book['apartment']?>
        </td>
        <td>
          <?php print $book['booking_id']?>
        </td>
        <td>
          <input id="input-agreement-<?php print $book['booking_id'];?>" data-booking-nid="<?php print $book['booking_id']?>" class="input-agreement" placeholder="№ договора"><br>
          <input id="input-agreement-name-<?php print $book['booking_id'];?>" data-booking-nid="<?php print $book['booking_id']?>" class="input-agreement-name" placeholder="ФИО по договору">
        </td>
        <?php print $book['but']?>
        <?php if(isset($book['status'])):?>
          <td><span><?php print $book['status']['title']; ?></span><br>
            <?php print $book['status']['img']; ?>
          </td>
        <?php endif; ?>
      </tr>
    <?php endforeach; ?>
  </table>
<?php else: ?>
  <div class="col-xs-12 empty-message">
    <h3>ни одна заявка на квартиру не была подана</h3>
    <p>это можно сделать на странице квартиры</p>
    <?php print $search_link; ?>
  </div>
<?php endif; ?>
