<?php

function toInt(string $number): int{
    return (int)$number;
}

/*
 * n = Sokak Lambası Sayısı
 * m = Uzunluk
 * d = Minimum Işık Yarıçapı
 */
[$n, $m] = array_map('toInt', explode(' ', trim(fgets(STDIN))));
$numbers = array_map('toInt', explode(' ', trim(fgets(STDIN))));
$sort = rsort($numbers, SORT_NUMERIC);
$reduce = [];
for($i = 0; $i < $n;){
    array_push($reduce, $numbers[$i] - $numbers[++$i] ?? 0);
}

$withStart = min($numbers) * 2;
$withFinish = ($m - max($numbers)) * 2;
array_push($reduce, $withStart, $withFinish);

$d = max($reduce) / 2;

echo $d;
