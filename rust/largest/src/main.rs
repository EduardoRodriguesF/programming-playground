// fn largest<T: PartialOrd>(list: &[T]) -> &T { ... also works
fn largest<T>(list: &[T]) -> &T where T: PartialOrd {
    let mut result = &list[0];

    for item in list {
        if item > result {
            result = item;
        }
    }

    result
}

fn main() {
    let list = vec![0, 53, 20, 52, 39];
    let largest = largest(&list);

    println!("largest is {}", &largest);
}
