<?php

/**
 * Process variables for realty-plan-plans-apartments-page.tpl.php.
 */
function realty_plan_preprocess_realty_plan_plans_apartments_page(&$vars) {
  $a = 1;
  for($i = 0; $i < 45; $i++) {
    $vars['forms'][] = drupal_get_form('realty_plan_add_plans_apartments_form', $i);
  }

  $menu = array(
    0 => array(
      0
    )
  );
  $menu = '<ul class="tabs primary">
    <li class="active"><a href="/admin/content/plans_apartments" class="active">Планировки<span class="element-invisible">(активная вкладка)</span></a></li>
    <li><a href="/admin/content/plans_apartments/update_apartments">Обновить</a></li>
    </ul>';
}