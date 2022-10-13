use std::fs::File;
use std::io::ErrorKind;

fn main() {
    let greeting_file = match File::open("hello.txt") {
        Ok(file) => file,
        Err(error) => match error.kind() {
            ErrorKind::NotFound => match File::create("hello.txt") {
                Ok(new_file) => new_file,
                Err(e) => panic!("Problem creating the file: {:?}", e),
            }
            other_error => {
                panic!("Problem opening the file: {:?}", other_error)
            }
        }
    };

    println!("{:?}", greeting_file);
}
