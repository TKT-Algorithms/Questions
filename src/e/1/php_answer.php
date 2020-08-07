<?php

/*
 * NULL = 0
 * X = 1
 * O = 2
 */
class Matrix{

    private array $matrix = [];
    private int $rows;
    private int $columns;

    public function __construct(int $rows, int $columns, array $set = []){
        $this->rows = max(1, $rows);
        $this->columns = max(1, $columns);
        $this->set($set);
    }

    public function set(array $set): void{
        for($r = 0; $r < $this->rows; ++$r){
            $this->matrix[$r] = [];
            for($c = 0; $c < $this->columns; ++$c){
                $this->matrix[$r][$c] = $set[$r][$c] ?? 0;
            }
        }
    }

    public function getRows(): int{
        return $this->rows;
    }

    public function getColumns(): int{
        return $this->columns;
    }

    public function setElement(int $row, int $column, int $value): bool{
        if($row > $this->rows || $row < 0 || $column > $this->columns || $column < 0){
            return false;
        }

        $this->matrix[$row][$column] = $value;
        return true;
    }

    /**
     * @param int $row
     * @param int $column
     *
     * @return int|null
     */
    public function getElement(int $row, int $column){
        if($row > $this->rows || $row < 0 || $column > $this->columns || $column < 0){
            return null;
        }

        return $this->matrix[$row][$column];
    }

}

class BoardWriter{

    private int $vertical = 4;
    private Matrix $matrix;

    private const SPACE = ' ';
    private const WALL = '||';

    private array $table = [];
    private array $drawData = [
        ['#', '1', '2', '3'],
        ['a', null, null, null],
        ['b', null, null, null],
        ['c', null, null, null]
    ];

    public function __construct(Matrix $matrix){
        $this->matrix = $matrix;
    }

    private function drawLine(int $line): void{
        if($line < $this->vertical){
            $column = -1;
            foreach($this->drawData[$line] as $row){
                $row ??= $this->matrix->getElement($line - 1, $column);
                $this->draw([
                    self::SPACE,
                    is_int($row) ? $this->detectXO($row) : $row
                ]);
                $column++;
            }
        }
    }

    /**
     * @param string[]|string $char
     */
    private function draw($char): void{
        if(is_string($char)){
            $char = [$char];
        }

        array_push($this->table, ...$char);
    }

    private function detectXO(int $index): string{
        return Legacy::SYMBOL_INDEXES[$index] ?? Legacy::NULL;
    }

    public function __toString(): string{
        $this->table = [];
        for($v = 0; $v < $this->vertical; ++$v){
            $this->draw(self::WALL);
            $this->drawLine($v);
            $this->draw([self::SPACE, self::WALL, PHP_EOL]);
        }

        return implode('', $this->table);
    }

}

class Vector2{

    private int $x;
    private int $y;

    public function __construct(int $x = 0, int $y = 0){
        $this->x = $x;
        $this->y = $y;
    }

    public function getX(){
        return $this->x;
    }

    public function getY(): int{
        return $this->y;
    }

    public function __toString(): string{
        return ['a', 'b', 'c'][$this->x] . ($this->y + 1);
    }

}

abstract class Player{

    protected string $symbol;

    public function __construct(string $symbol){
        $this->symbol = $symbol;
    }

    public function getSymbol(): string{
        return $this->symbol;
    }

    public function getSymbolByInt(): int{
        return $this->symbol === Legacy::X ? Legacy::X_INDEX : Legacy::O_INDEX;
    }

    abstract public function getName(): string;

}

class Human extends Player{

    public function getName(): string{
        return 'Oyuncu';
    }

}

class CPU extends Player{

    public function getName(): string{
        return 'Bilgisayar';
    }

}

class MinimaxPacket{

    private Vector2 $vector2;
    private int $score;

    public function __construct(Vector2 $vector2, int $score){
        $this->vector2 = $vector2;
        $this->score = $score;
    }

    public function getVector2(): Vector2{
        return $this->vector2;
    }

    public function setVector(Vector2 $vector2): void{
        $this->vector2 = $vector2;
    }

    public function getScore(): int{
        return $this->score;
    }

}

class Game{

    use Writer;

    private int $maxRound = 9;
    private int $currentRound = 0;
    private bool $isFinish = false;

    private Human $human;
    private CPU $cpu;
    private BoardWriter $writer;
    private Matrix $matrix;

    private GameController $controller;

    private array $axisAlignmentData;

    /** @var Human|CPU */
    private $sequence;

    public function __construct(){
        $this->axisAlignmentData = [
            'A1' => new Vector2(0, 0),
            'A2' => new Vector2(0, 1),
            'A3' => new Vector2(0, 2),
            'B1' => new Vector2(1, 0),
            'B2' => new Vector2(1, 1),
            'B3' => new Vector2(1, 2),
            'C1' => new Vector2(2, 0),
            'C2' => new Vector2(2, 1),
            'C3' => new Vector2(2, 2),
        ];
        $this->matrix = new Matrix(Legacy::VERTICAL, Legacy::HORIZONTAL);
        $this->writer = new BoardWriter($this->matrix);

        $this->write(PHP_EOL, Legacy::NEXT_LINE_NONE, false);
        $this->write('Yenilmez Tic Tac Toe AI', Legacy::NEXT_LINE_MULTIPLY);
    }

    public function start(){
        $setup = new Setup($this);
        $setup->start(); // wait for finish setup

        while($this->currentRound < $this->maxRound && !$this->isFinish){
            if($this->sequence instanceof Human){
                $this->write("Oyuncunun sırası ({$this->getHuman()->getSymbol()}): ", Legacy::NEXT_LINE_NONE);
                $line = trim(fgets(STDIN));
                $axis = $this->getAxisAlignment(strtoupper($line));
                if($axis === null){
                    $this->write('Geçersiz alan. Lütfen oyun tablosunda bulunan bir alanı seçin.', Legacy::NEXT_LINE_MULTIPLY);
                }else{
                    $element = $this->matrix->getElement($axis->getX(), $axis->getY());
                    if($element === Legacy::NULL_INDEX){
                        $this->next($axis, $this->cpu);
                    }else{
                        $this->write('Bu alan dolu. Lütfen boş bir alan seçin.', Legacy::NEXT_LINE_MULTIPLY);
                    }
                }
            }else{
                if($this->currentRound === 0){
                    $axis = $this->getAxisAlignment(array_rand($this->axisAlignmentData));
                }else{
                    $axis = $this->getController()->minimax(
                        $this->getMatrix(),
                        $this->maxRound - $this->currentRound,
                        $this->getCPU()->getSymbolByInt()
                    )->getVector2();
                }

                $this->write("Bilgisayarın Sırası ({$this->getCPU()->getSymbol()}): {$axis}" . PHP_EOL, Legacy::NEXT_LINE_NONE);
                $this->next($axis, $this->getHuman());
            }
        }
    }

    public function next(Vector2 $axis, Player $sequence){
        $this->matrix->setElement(
            $axis->getX(),
            $axis->getY(),
            $this->sequence->getSymbolByInt()
        );

        $this->write($this->getBoardWriter(), Legacy::NEXT_LINE_MULTIPLY, false, 1);

        $isFinish = $this->getController()->evaluate();
        if($isFinish !== Legacy::UNFINISHED){
            $this->isFinish = true;
            switch($isFinish){
                case Legacy::X_WON:
                    $winner = "X Kazandı ({$this->sequence->getName()})";
                    break;

                case Legacy::O_WON:
                    $winner = "O Kazandı ({$this->sequence->getName()})";
                    break;

                default:
                    $winner = 'Berabere Bitti';
                    break;
            }
            $this->write("Oyun bitti. Sonuç: {$winner}");
        }

        $this->setSequence($sequence);
        $this->currentRound++;
    }

    public function getAxisAlignment(string $axis): ?Vector2{
        return $this->axisAlignmentData[$axis] ?? null;
    }

    public function getBoardWriter(): BoardWriter{
        return $this->writer;
    }

    public function getMatrix(): Matrix{
        return $this->matrix;
    }

    public function getController(): GameController{
        return $this->controller;
    }

    public function setController(GameController $controller): void{
        $this->controller = $controller;
    }

    public function setHuman(Human $human): void{
        $this->human = $human;
    }

    public function getHuman(): Human{
        return $this->human;
    }

    public function setCPU(CPU $cpu): void{
        $this->cpu = $cpu;
    }

    public function getCPU(): CPU{
        return $this->cpu;
    }

    public function setSequence(Player $sequence): void{
        $this->sequence = $sequence;
    }

}

class Setup{

    use Writer;

    private Game $game;

    public function __construct(Game $game){
        $this->game = $game;
    }

    public function start(){
        $this->write('Lütfen karakterinizi seçin (X veya O): ', Legacy::NEXT_LINE_NONE);
        while(true){
            $line = trim(fgets(STDIN));
            $upper = strtoupper($line);
            if($line !== "" && in_array($upper, array_values(Legacy::SYMBOL_INDEXES))){
                $this->game->setHuman($human = new Human($upper));
                $this->game->setCPU($cpu = new CPU($upper === Legacy::X ? Legacy::O : Legacy::X));
                $this->game->setSequence($upper === Legacy::X ? $human : $cpu);

                $this->write($this->game->getBoardWriter(), Legacy::NEXT_LINE_MULTIPLY, false, 1);
                $this->game->setController(new GameController($this->game));
                break;
            }else{
                $this->write('Lütfen geçerli bir karakter girin.', Legacy::NEXT_LINE_MULTIPLY);
                $this->write('Lütfen karakterinizi seçin (X veya O): ', Legacy::NEXT_LINE_NONE);
            }
        }
    }

}

trait Writer{

    /**
     * @param string $context
     * @param int    $nextLine
     * @param bool   $prefix
     * @param int    $multiplier
     */
    private function write(
        string $context,
        int $nextLine = Legacy::NEXT_LINE_BEHIND,
        bool $prefix = true,
        int $multiplier = 2
    ): void{
        $text = '';
        if($nextLine === Legacy::NEXT_LINE_BEFORE || $nextLine === Legacy::NEXT_LINE_MULTIPLY){
            $text .= PHP_EOL;
        }

        if($prefix){
            $text .= Legacy::PREFIX . ' ';
        }

        $text .= $context;

        if($nextLine === Legacy::NEXT_LINE_BEHIND || $nextLine === Legacy::NEXT_LINE_MULTIPLY){
            $text .= str_repeat(PHP_EOL, $multiplier);
        }

        echo $text;
    }

}

class GameController{

    private Game $game;
    private array $scores;

    public function __construct(Game $game){
        $this->game = $game;
        $this->scores = [
            $game->getCPU()->getSymbolByInt() => 1,
            $game->getHuman()->getSymbolByInt() => -1
        ];
    }

    public function minimax(Matrix $matrix, int $depth, int $player): MinimaxPacket{
        $cpu = $this->game->getCPU();
        $optimumAxisAlignment = new MinimaxPacket(
            new Vector2(-1, -1),
            $player === $cpu->getSymbolByInt() ? PHP_INT_MIN : PHP_INT_MAX
        );

        if($depth === 0 || $this->over()){
            return new MinimaxPacket(
                new Vector2(-1, -1),
                $this->toScore($this->evaluate())
            );
        }

        for($r = 0; $r < $matrix->getRows(); $r++){
            for($c = 0; $c < $matrix->getColumns(); $c++){
                if($matrix->getElement($r, $c) === Legacy::NULL_INDEX){
                    $matrix->setElement($r, $c, $player);
                    $score = $this->minimax(
                        $matrix,
                        $depth - 1,
                        $player === Legacy::X_INDEX ? Legacy::O_INDEX : Legacy::X_INDEX
                    );
                    $matrix->setElement($r, $c, Legacy::NULL_INDEX);

                    $score->setVector(new Vector2($r, $c));

                    if($player === $cpu->getSymbolByInt()){
                        if($score->getScore() > $optimumAxisAlignment->getScore()){
                            $optimumAxisAlignment = $score;
                        }
                    }else{
                        if($score->getScore() < $optimumAxisAlignment->getScore()){
                            $optimumAxisAlignment = $score;
                        }
                    }
                }
            }
        }

        return $optimumAxisAlignment;
    }

    public function evaluate(): int{
        $matrix = $this->game->getMatrix();

        // Vertical Axis
        for($v = 0; $v < $matrix->getRows(); ++$v){
            $middle = $matrix->getElement(1, $v);
            if($middle !== Legacy::NULL_INDEX){
                if(
                    $matrix->getElement(0, $v) === $middle
                    &&
                    $matrix->getElement(2, $v) === $middle
                ){
                    return $middle;
                }
            }
        }

        // Horizontal Axis
        for($h = 0; $h < $matrix->getColumns(); ++$h){
            $middle = $matrix->getElement($h, 1);
            if($middle !== Legacy::NULL_INDEX){
                if(
                    $matrix->getElement($h, 0) === $middle
                    &&
                    $matrix->getElement($h, 2) === $middle
                ){
                    return $middle;
                }
            }
        }

        $middle = $matrix->getElement(1, 1); // Cross Axis Middle
        if($middle !== Legacy::NULL_INDEX){
            // Cross Axis (Top Left, Bottom Right)
            if(
                $matrix->getElement(0, 0) === $middle
                &&
                $matrix->getElement(2, 2) === $middle
            ){
                return $middle;
            }

            // Cross Axis (Top Right, Bottom Left)
            if(
                $matrix->getElement(2, 0) === $middle
                &&
                $matrix->getElement(0, 2) === $middle
            ){
                return $middle;
            }
        }

        $empty = false;
        for($v = 0; $v < $matrix->getRows(); ++$v){
            for($h = 0; $h < $matrix->getColumns(); ++$h){
                $element = $matrix->getElement($v, $h);
                if($element === Legacy::NULL_INDEX){
                    $empty = true;
                    break;
                }
            }
        }

        return $empty ? Legacy::UNFINISHED : Legacy::DRAW;
    }

    public function over(){
        $evaluate = $this->evaluate();
        return $evaluate === Legacy::X_WON || $evaluate === Legacy::O_WON;
    }

    public function toScore(int $winner){
        return $this->scores[$winner] ?? 0;
    }

}

interface Legacy{

    public const PREFIX = '[*]';

    public const NEXT_LINE_NONE = 0x1;
    public const NEXT_LINE_BEFORE = 0x2;
    public const NEXT_LINE_BEHIND = 0x4;
    public const NEXT_LINE_MULTIPLY = self::NEXT_LINE_BEFORE ^ self:: NEXT_LINE_BEHIND;

    public const X_WON = 0x1;
    public const O_WON = 0x2;
    public const DRAW = 0x4;
    public const UNFINISHED = 0x8;

    public const X_INDEX = 1;
    public const O_INDEX = 2;
    public const NULL_INDEX = 0;

    public const X = 'X';
    public const O = 'O';
    public const NULL = '.';

    public const SYMBOL_INDEXES = [
        self::X_INDEX => self::X,
        self::O_INDEX => self::O
    ];

    public const VERTICAL = 3;
    public const HORIZONTAL = 3;

}

$game = new Game();
$game->start();
