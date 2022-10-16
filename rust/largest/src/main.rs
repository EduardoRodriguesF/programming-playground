fn largest<T: PartialOrd>(list: &[T]) -> &T {
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
