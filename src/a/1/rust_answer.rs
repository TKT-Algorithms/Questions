static LUCKY_NUMBERS: [u16; 12] = [
    4, 7,
    44, 47, 74, 77,
    444, 447, 477, 744, 774, 777
];

fn main() {
    let mut input: String = String::new();
    let mut lucky: bool = false;

    print!("Bir sayı giriniz: ");

    if let Ok(_) = std::io::stdin().read_line(&mut input) {
        input = input.replace("\n", "").replace("\r", "");
        if LUCKY_NUMBERS.iter()
            .filter(|i| {
                **i % input.parse::<u16>().unwrap() == 0
            }).collect::<Vec<&u16>>().len() != 0 {
            lucky = true
        }
    }

    println!("{}", if lucky {
        "Yes"
    } else {
        "No"
    });
}
