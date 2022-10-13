use std::fs::File;
use std::io::ErrorKind;

fn create_file(filename: &str) -> File {
    match File::create(filename) {
        Ok(file) => file,
        Err(error) => panic!("Problem creating the file: {:?}", error),
    }
}

fn read_or_create(filename: &str) -> File {
    match File::open(filename) {
        Ok(file) => file,
        Err(error) => match error.kind() {
            ErrorKind::NotFound => create_file(filename),
            other_error => {
                panic!("Problem opening the file: {:?}", other_error)
            }
        }
    }
}

fn main() {
    let greeting_file = read_or_create("hello.txt");

    println!("{:?}", greeting_file);
}
