<div style="height: 40px">
  <ul class="tabs primary">
    <li class="active">
      <a href="/admin/content/plans_apartments" class="active">Планировки<span class="element-invisible">(активная вкладка)</span></a>
    </li>
    <li>
      <a href="/admin/content/plans_apartments/update_apartments">Обновление планировок</a>
    </li>
  </ul>
</div>

<div>
  <?php foreach($forms as $i => $form):?>
    <?php $i % 2 == 0 ? $color = '#bebfb9' :   $color = '#ECEFE0';?>
    <div style="background-color:<?php print $color; ?>; padding: 8px 10px">
     <?php print render($form); ?>
    </div>
  <?php endforeach; ?>
</div>