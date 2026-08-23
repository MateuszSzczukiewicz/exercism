fn count_flowers(garden: &[&str], row_index: usize, column_index: usize) -> usize {
    let directions: [(isize, isize); 8] = [
        (-1, -1),
        (-1, 0),
        (-1, 1),
        (0, -1),
        (0, 1),
        (1, -1),
        (1, 0),
        (1, 1),
    ];

    directions
        .into_iter()
        .filter_map(|(row_delta, column_delta)| {
            let target_row = row_index as isize + row_delta;
            let target_column = column_index as isize + column_delta;

            if target_row < 0 || target_column < 0 {
                None
            } else {
                Some((target_row as usize, target_column as usize))
            }
        })
        .filter(|&(target_row, target_column)| check_flower(garden, target_row, target_column))
        .count()
}

fn check_flower(garden: &[&str], row_index: usize, column_index: usize) -> bool {
    garden
        .get(row_index)
        .and_then(|row| row.chars().nth(column_index))
        == Some('*')
}

pub fn annotate(garden: &[&str]) -> Vec<String> {
    garden
        .iter()
        .enumerate()
        .map(|(row_index, row)| {
            row.chars()
                .enumerate()
                .map(|(column_index, field)| {
                    if field == '*' {
                        field
                    } else {
                        let count = count_flowers(garden, row_index, column_index);

                        if count > 0 {
                            char::from_digit(count as u32, 10)
                                .expect("count of neighboring flowers must be between 1 and 8")
                        } else {
                            ' '
                        }
                    }
                })
                .collect()
        })
        .collect()
}
