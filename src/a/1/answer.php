static $luckyNumbers = [4, 7, 44, 47, 74, 77, 444, 447, 474, 477, 744, 747, 774, 777];

echo 'Sayı Girin: ';
while($line = trim(fgets(STDIN))){
    $filter = array_filter($luckyNumbers, function(int $lucky) use ($line){
        return (int)$line % $lucky === 0;
    });

    echo (count($filter) === 0 ? 'NO' : 'YES') . PHP_EOL;

    echo 'Sayı Girin: ';
}
