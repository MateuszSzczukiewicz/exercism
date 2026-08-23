fn count_flowers(garden: &[&str], row_index: usize, column_index: usize) -> usize {
    let mut counter = 0;

    if check_flower(garden, row_index + 1, column_index) {
        counter += 1;
    }

    if check_flower(garden, row_index + 1, column_index + 1) {
        counter += 1;
    }

    if check_flower(garden, row_index, column_index + 1) {
        counter += 1;
    }

    if row_index >= 1 {
        if check_flower(garden, row_index - 1, column_index) {
            counter += 1;
        }

        if check_flower(garden, row_index - 1, column_index + 1) {
            counter += 1;
        }
    }

    if column_index >= 1 {
        if check_flower(garden, row_index, column_index - 1) {
            counter += 1;
        }

        if check_flower(garden, row_index + 1, column_index - 1) {
            counter += 1;
        }
    }

    if row_index >= 1 && column_index >= 1 && check_flower(garden, row_index - 1, column_index) {
        counter += 1;
    }

    counter
}

fn check_flower(garden: &[&str], row_index: usize, column_index: usize) -> bool {
    if row_index >= garden.len() {
        return false;
    }

    let row = garden[row_index];

    let field = row.chars().nth(column_index);

    match field {
        Some(value) => value == '*',
        None => false,
    }
}

pub fn annotate(garden: &[&str]) -> Vec<String> {
    let mut new_garden: Vec<String> = Vec::new();

    for (i, row) in garden.iter().enumerate() {
        for (j, field) in row.chars().enumerate() {
            let mut result = String::from("");

            if check_flower(garden, i, j) {
                result.push(field);
            } else {
                let count = count_flowers(garden, i, j);

                if count > 0 {
                    result.push_str(&count.to_string());
                } else {
                    result.push(' ');
                }
            }

            new_garden.push(result);
        }
    }

    new_garden
}
