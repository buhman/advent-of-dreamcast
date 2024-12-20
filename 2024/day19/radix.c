static uint32_t count_substring_matches(const char * s, int length)
{
  int ix = 0;
  uint32_t matches = 0;
  if (ix >= length)
    return matches;
  switch (s[ix++]) {
  case 'w':
    matches |= (1 << (ix - 1));
    if (ix >= length) {
      return matches;
    }
    switch (s[ix++]) {
    case 'u':
      matches |= (1 << (ix - 1));
      if (ix >= length) {
        return matches;
      }
      switch (s[ix++]) {
      case 'r':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'w':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          default:
            break;
          }
          break;
        case 'u':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      case 'b':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'b':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'w':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'b':
              matches |= (1 << (ix - 1));
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        case 'u':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'g':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'b':
              matches |= (1 << (ix - 1));
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      case 'u':
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'w':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'r':
            matches |= (1 << (ix - 1));
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        case 'u':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'b':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'u':
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              case 'b':
                matches |= (1 << (ix - 1));
                if (ix >= length) {
                  return matches;
                }
                switch (s[ix++]) {
                default:
                  break;
                }
                break;
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        case 'b':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'b':
            matches |= (1 << (ix - 1));
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      case 'w':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'b':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      case 'g':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'w':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'b':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'w':
              matches |= (1 << (ix - 1));
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              default:
                break;
              }
              break;
            case 'b':
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              case 'r':
                if (ix >= length) {
                  return matches;
                }
                switch (s[ix++]) {
                case 'u':
                  matches |= (1 << (ix - 1));
                  if (ix >= length) {
                    return matches;
                  }
                  switch (s[ix++]) {
                  default:
                    break;
                  }
                  break;
                default:
                  break;
                }
                break;
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        case 'r':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      default:
        break;
      }
      break;
    case 'g':
      matches |= (1 << (ix - 1));
      if (ix >= length) {
        return matches;
      }
      switch (s[ix++]) {
      case 'r':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'w':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'r':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'r':
              matches |= (1 << (ix - 1));
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        case 'b':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'r':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'u':
              matches |= (1 << (ix - 1));
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        case 'g':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'b':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'r':
              matches |= (1 << (ix - 1));
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      case 'u':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'u':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          default:
            break;
          }
          break;
        case 'g':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      case 'w':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'r':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          default:
            break;
          }
          break;
        case 'b':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'r':
            matches |= (1 << (ix - 1));
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      case 'g':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'w':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          default:
            break;
          }
          break;
        case 'g':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'r':
            matches |= (1 << (ix - 1));
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'w':
              matches |= (1 << (ix - 1));
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      case 'b':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'w':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'u':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'g':
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              case 'g':
                matches |= (1 << (ix - 1));
                if (ix >= length) {
                  return matches;
                }
                switch (s[ix++]) {
                default:
                  break;
                }
                break;
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      default:
        break;
      }
      break;
    case 'w':
      if (ix >= length) {
        return matches;
      }
      switch (s[ix++]) {
      case 'g':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'u':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'u':
            matches |= (1 << (ix - 1));
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      case 'r':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'u':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          default:
            break;
          }
          break;
        case 'g':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'r':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'b':
              matches |= (1 << (ix - 1));
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      case 'w':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'r':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          default:
            break;
          }
          break;
        case 'b':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'g':
            matches |= (1 << (ix - 1));
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      case 'u':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'b':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'b':
            matches |= (1 << (ix - 1));
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            default:
              break;
            }
            break;
          case 'r':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'w':
              matches |= (1 << (ix - 1));
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      case 'b':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'r':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'w':
            matches |= (1 << (ix - 1));
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        case 'u':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'g':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'w':
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              case 'b':
                if (ix >= length) {
                  return matches;
                }
                switch (s[ix++]) {
                case 'b':
                  matches |= (1 << (ix - 1));
                  if (ix >= length) {
                    return matches;
                  }
                  switch (s[ix++]) {
                  default:
                    break;
                  }
                  break;
                default:
                  break;
                }
                break;
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      default:
        break;
      }
      break;
    case 'r':
      matches |= (1 << (ix - 1));
      if (ix >= length) {
        return matches;
      }
      switch (s[ix++]) {
      case 'r':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'g':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'r':
            matches |= (1 << (ix - 1));
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            default:
              break;
            }
            break;
          case 'g':
            matches |= (1 << (ix - 1));
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      case 'b':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'w':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'r':
            matches |= (1 << (ix - 1));
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      case 'g':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'w':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'b':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'r':
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              case 'u':
                matches |= (1 << (ix - 1));
                if (ix >= length) {
                  return matches;
                }
                switch (s[ix++]) {
                default:
                  break;
                }
                break;
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          case 'r':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'w':
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              case 'g':
                if (ix >= length) {
                  return matches;
                }
                switch (s[ix++]) {
                case 'r':
                  matches |= (1 << (ix - 1));
                  if (ix >= length) {
                    return matches;
                  }
                  switch (s[ix++]) {
                  default:
                    break;
                  }
                  break;
                default:
                  break;
                }
                break;
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          case 'u':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'u':
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              case 'u':
                if (ix >= length) {
                  return matches;
                }
                switch (s[ix++]) {
                case 'r':
                  matches |= (1 << (ix - 1));
                  if (ix >= length) {
                    return matches;
                  }
                  switch (s[ix++]) {
                  default:
                    break;
                  }
                  break;
                default:
                  break;
                }
                break;
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        case 'r':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      case 'u':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'g':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'g':
            matches |= (1 << (ix - 1));
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        case 'r':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'r':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'r':
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              case 'g':
                matches |= (1 << (ix - 1));
                if (ix >= length) {
                  return matches;
                }
                switch (s[ix++]) {
                default:
                  break;
                }
                break;
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      case 'w':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        default:
          break;
        }
        break;
      default:
        break;
      }
      break;
    case 'b':
      matches |= (1 << (ix - 1));
      if (ix >= length) {
        return matches;
      }
      switch (s[ix++]) {
      case 'r':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'b':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'u':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'r':
              matches |= (1 << (ix - 1));
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          case 'g':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'b':
              matches |= (1 << (ix - 1));
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        case 'r':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'r':
            matches |= (1 << (ix - 1));
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            default:
              break;
            }
            break;
          case 'w':
            matches |= (1 << (ix - 1));
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'u':
              matches |= (1 << (ix - 1));
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          case 'u':
            matches |= (1 << (ix - 1));
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        case 'w':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'b':
            matches |= (1 << (ix - 1));
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      case 'b':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'g':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          default:
            break;
          }
          break;
        case 'b':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'g':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'u':
              matches |= (1 << (ix - 1));
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        case 'w':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'b':
            matches |= (1 << (ix - 1));
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      case 'w':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'b':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          default:
            break;
          }
          break;
        case 'r':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'u':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'g':
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              case 'u':
                matches |= (1 << (ix - 1));
                if (ix >= length) {
                  return matches;
                }
                switch (s[ix++]) {
                default:
                  break;
                }
                break;
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      case 'u':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        default:
          break;
        }
        break;
      case 'g':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        default:
          break;
        }
        break;
      default:
        break;
      }
      break;
    default:
      break;
    }
    break;
  case 'u':
    matches |= (1 << (ix - 1));
    if (ix >= length) {
      return matches;
    }
    switch (s[ix++]) {
    case 'w':
      matches |= (1 << (ix - 1));
      if (ix >= length) {
        return matches;
      }
      switch (s[ix++]) {
      case 'w':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'g':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'b':
            matches |= (1 << (ix - 1));
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            default:
              break;
            }
            break;
          case 'r':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'g':
              matches |= (1 << (ix - 1));
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        case 'b':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      case 'b':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'g':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'w':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'b':
              matches |= (1 << (ix - 1));
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          case 'u':
            matches |= (1 << (ix - 1));
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        case 'r':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      case 'u':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'u':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'g':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'b':
              matches |= (1 << (ix - 1));
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          case 'r':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'w':
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              case 'b':
                if (ix >= length) {
                  return matches;
                }
                switch (s[ix++]) {
                case 'b':
                  matches |= (1 << (ix - 1));
                  if (ix >= length) {
                    return matches;
                  }
                  switch (s[ix++]) {
                  default:
                    break;
                  }
                  break;
                default:
                  break;
                }
                break;
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        case 'b':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'w':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'g':
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              case 'r':
                matches |= (1 << (ix - 1));
                if (ix >= length) {
                  return matches;
                }
                switch (s[ix++]) {
                default:
                  break;
                }
                break;
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      case 'r':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'w':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'r':
            matches |= (1 << (ix - 1));
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        case 'g':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      case 'g':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'g':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'r':
            matches |= (1 << (ix - 1));
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      default:
        break;
      }
      break;
    case 'g':
      matches |= (1 << (ix - 1));
      if (ix >= length) {
        return matches;
      }
      switch (s[ix++]) {
      case 'w':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'b':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'b':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'r':
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              case 'w':
                if (ix >= length) {
                  return matches;
                }
                switch (s[ix++]) {
                case 'g':
                  matches |= (1 << (ix - 1));
                  if (ix >= length) {
                    return matches;
                  }
                  switch (s[ix++]) {
                  default:
                    break;
                  }
                  break;
                default:
                  break;
                }
                break;
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        case 'r':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'r':
            matches |= (1 << (ix - 1));
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'w':
              matches |= (1 << (ix - 1));
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        case 'u':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'w':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'w':
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              case 'r':
                matches |= (1 << (ix - 1));
                if (ix >= length) {
                  return matches;
                }
                switch (s[ix++]) {
                default:
                  break;
                }
                break;
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        case 'w':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'r':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'b':
              matches |= (1 << (ix - 1));
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        case 'g':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      case 'u':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'g':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'b':
            matches |= (1 << (ix - 1));
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      case 'r':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        default:
          break;
        }
        break;
      case 'g':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'b':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'b':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'g':
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              case 'r':
                if (ix >= length) {
                  return matches;
                }
                switch (s[ix++]) {
                case 'w':
                  matches |= (1 << (ix - 1));
                  if (ix >= length) {
                    return matches;
                  }
                  switch (s[ix++]) {
                  default:
                    break;
                  }
                  break;
                default:
                  break;
                }
                break;
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        case 'r':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      case 'b':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'w':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'w':
            matches |= (1 << (ix - 1));
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            default:
              break;
            }
            break;
          case 'u':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'g':
              matches |= (1 << (ix - 1));
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        case 'u':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'u':
            matches |= (1 << (ix - 1));
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      default:
        break;
      }
      break;
    case 'u':
      matches |= (1 << (ix - 1));
      if (ix >= length) {
        return matches;
      }
      switch (s[ix++]) {
      case 'g':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'u':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'w':
            matches |= (1 << (ix - 1));
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        case 'w':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'g':
            matches |= (1 << (ix - 1));
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        case 'b':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'r':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'w':
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              case 'u':
                matches |= (1 << (ix - 1));
                if (ix >= length) {
                  return matches;
                }
                switch (s[ix++]) {
                default:
                  break;
                }
                break;
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      case 'u':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'b':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'g':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'g':
              matches |= (1 << (ix - 1));
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              default:
                break;
              }
              break;
            case 'r':
              matches |= (1 << (ix - 1));
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          case 'r':
            matches |= (1 << (ix - 1));
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        case 'g':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'r':
            matches |= (1 << (ix - 1));
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        case 'u':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          default:
            break;
          }
          break;
        case 'w':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'r':
            matches |= (1 << (ix - 1));
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      case 'r':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'b':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'w':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'w':
              matches |= (1 << (ix - 1));
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        case 'g':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'u':
            matches |= (1 << (ix - 1));
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            default:
              break;
            }
            break;
          case 'g':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'r':
              matches |= (1 << (ix - 1));
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        case 'r':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'r':
            matches |= (1 << (ix - 1));
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        case 'w':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'r':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'b':
              matches |= (1 << (ix - 1));
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        case 'u':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      case 'b':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'r':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          default:
            break;
          }
          break;
        case 'b':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'w':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'w':
              matches |= (1 << (ix - 1));
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              case 'b':
                matches |= (1 << (ix - 1));
                if (ix >= length) {
                  return matches;
                }
                switch (s[ix++]) {
                default:
                  break;
                }
                break;
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        case 'u':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'u':
            matches |= (1 << (ix - 1));
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      case 'w':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'w':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'r':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'b':
              matches |= (1 << (ix - 1));
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      default:
        break;
      }
      break;
    case 'b':
      matches |= (1 << (ix - 1));
      if (ix >= length) {
        return matches;
      }
      switch (s[ix++]) {
      case 'b':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'w':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'b':
            matches |= (1 << (ix - 1));
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        case 'b':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          default:
            break;
          }
          break;
        case 'r':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      case 'w':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        default:
          break;
        }
        break;
      case 'r':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'g':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'w':
            matches |= (1 << (ix - 1));
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      case 'u':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        default:
          break;
        }
        break;
      case 'g':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'u':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      default:
        break;
      }
      break;
    case 'r':
      matches |= (1 << (ix - 1));
      if (ix >= length) {
        return matches;
      }
      switch (s[ix++]) {
      case 'g':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'r':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      case 'u':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'g':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'b':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'g':
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              case 'u':
                matches |= (1 << (ix - 1));
                if (ix >= length) {
                  return matches;
                }
                switch (s[ix++]) {
                default:
                  break;
                }
                break;
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        case 'w':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'g':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'g':
              matches |= (1 << (ix - 1));
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      case 'w':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'r':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          default:
            break;
          }
          break;
        case 'g':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'r':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'g':
              matches |= (1 << (ix - 1));
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        case 'b':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'u':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'g':
              matches |= (1 << (ix - 1));
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      case 'r':
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'u':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'w':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'b':
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              case 'u':
                matches |= (1 << (ix - 1));
                if (ix >= length) {
                  return matches;
                }
                switch (s[ix++]) {
                default:
                  break;
                }
                break;
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          case 'u':
            matches |= (1 << (ix - 1));
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      case 'b':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'u':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'g':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'g':
              matches |= (1 << (ix - 1));
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              default:
                break;
              }
              break;
            case 'b':
              matches |= (1 << (ix - 1));
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        case 'g':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'g':
            matches |= (1 << (ix - 1));
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        case 'w':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'r':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'r':
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              case 'b':
                matches |= (1 << (ix - 1));
                if (ix >= length) {
                  return matches;
                }
                switch (s[ix++]) {
                default:
                  break;
                }
                break;
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      default:
        break;
      }
      break;
    default:
      break;
    }
    break;
  case 'r':
    if (ix >= length) {
      return matches;
    }
    switch (s[ix++]) {
    case 'b':
      matches |= (1 << (ix - 1));
      if (ix >= length) {
        return matches;
      }
      switch (s[ix++]) {
      case 'w':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'u':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'w':
            matches |= (1 << (ix - 1));
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            default:
              break;
            }
            break;
          case 'u':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'g':
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              case 'g':
                matches |= (1 << (ix - 1));
                if (ix >= length) {
                  return matches;
                }
                switch (s[ix++]) {
                default:
                  break;
                }
                break;
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        case 'w':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'g':
            matches |= (1 << (ix - 1));
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      case 'r':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'b':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'u':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'u':
              matches |= (1 << (ix - 1));
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        case 'w':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'b':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'u':
              matches |= (1 << (ix - 1));
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      case 'u':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'b':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      case 'b':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        default:
          break;
        }
        break;
      case 'g':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        default:
          break;
        }
        break;
      default:
        break;
      }
      break;
    case 'w':
      if (ix >= length) {
        return matches;
      }
      switch (s[ix++]) {
      case 'w':
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'r':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'r':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'g':
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              case 'u':
                matches |= (1 << (ix - 1));
                if (ix >= length) {
                  return matches;
                }
                switch (s[ix++]) {
                default:
                  break;
                }
                break;
              default:
                break;
              }
              break;
            case 'u':
              matches |= (1 << (ix - 1));
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        case 'w':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'u':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'u':
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              case 'g':
                matches |= (1 << (ix - 1));
                if (ix >= length) {
                  return matches;
                }
                switch (s[ix++]) {
                default:
                  break;
                }
                break;
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        case 'u':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      case 'r':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'w':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'g':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'b':
              matches |= (1 << (ix - 1));
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        case 'b':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'g':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'b':
              matches |= (1 << (ix - 1));
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        case 'g':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          default:
            break;
          }
          break;
        case 'r':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'g':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'u':
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              case 'g':
                if (ix >= length) {
                  return matches;
                }
                switch (s[ix++]) {
                case 'r':
                  matches |= (1 << (ix - 1));
                  if (ix >= length) {
                    return matches;
                  }
                  switch (s[ix++]) {
                  default:
                    break;
                  }
                  break;
                default:
                  break;
                }
                break;
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      case 'u':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'g':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'b':
            matches |= (1 << (ix - 1));
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      case 'g':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'r':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      case 'b':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'r':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      default:
        break;
      }
      break;
    case 'r':
      matches |= (1 << (ix - 1));
      if (ix >= length) {
        return matches;
      }
      switch (s[ix++]) {
      case 'b':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'w':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'g':
            matches |= (1 << (ix - 1));
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'b':
              matches |= (1 << (ix - 1));
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              default:
                break;
              }
              break;
            case 'g':
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              case 'b':
                matches |= (1 << (ix - 1));
                if (ix >= length) {
                  return matches;
                }
                switch (s[ix++]) {
                default:
                  break;
                }
                break;
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          case 'b':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'b':
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              case 'g':
                if (ix >= length) {
                  return matches;
                }
                switch (s[ix++]) {
                case 'u':
                  matches |= (1 << (ix - 1));
                  if (ix >= length) {
                    return matches;
                  }
                  switch (s[ix++]) {
                  default:
                    break;
                  }
                  break;
                default:
                  break;
                }
                break;
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        case 'g':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'r':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'r':
              matches |= (1 << (ix - 1));
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        case 'b':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'g':
            matches |= (1 << (ix - 1));
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      case 'r':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'w':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          default:
            break;
          }
          break;
        case 'u':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'b':
            matches |= (1 << (ix - 1));
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      case 'u':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'u':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'u':
            matches |= (1 << (ix - 1));
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        case 'g':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'b':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'b':
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              case 'u':
                if (ix >= length) {
                  return matches;
                }
                switch (s[ix++]) {
                case 'r':
                  matches |= (1 << (ix - 1));
                  if (ix >= length) {
                    return matches;
                  }
                  switch (s[ix++]) {
                  default:
                    break;
                  }
                  break;
                default:
                  break;
                }
                break;
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        case 'b':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'w':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'r':
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              case 'g':
                matches |= (1 << (ix - 1));
                if (ix >= length) {
                  return matches;
                }
                switch (s[ix++]) {
                default:
                  break;
                }
                break;
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      case 'w':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'b':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'w':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'g':
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              case 'r':
                if (ix >= length) {
                  return matches;
                }
                switch (s[ix++]) {
                case 'u':
                  matches |= (1 << (ix - 1));
                  if (ix >= length) {
                    return matches;
                  }
                  switch (s[ix++]) {
                  default:
                    break;
                  }
                  break;
                default:
                  break;
                }
                break;
              default:
                break;
              }
              break;
            case 'b':
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              case 'r':
                if (ix >= length) {
                  return matches;
                }
                switch (s[ix++]) {
                case 'r':
                  matches |= (1 << (ix - 1));
                  if (ix >= length) {
                    return matches;
                  }
                  switch (s[ix++]) {
                  default:
                    break;
                  }
                  break;
                default:
                  break;
                }
                break;
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          case 'b':
            matches |= (1 << (ix - 1));
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        case 'g':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'u':
            matches |= (1 << (ix - 1));
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      case 'g':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'w':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'b':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'g':
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              case 'b':
                matches |= (1 << (ix - 1));
                if (ix >= length) {
                  return matches;
                }
                switch (s[ix++]) {
                default:
                  break;
                }
                break;
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        case 'u':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'g':
            matches |= (1 << (ix - 1));
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      default:
        break;
      }
      break;
    case 'g':
      matches |= (1 << (ix - 1));
      if (ix >= length) {
        return matches;
      }
      switch (s[ix++]) {
      case 'w':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'r':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'w':
            matches |= (1 << (ix - 1));
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            default:
              break;
            }
            break;
          case 'b':
            matches |= (1 << (ix - 1));
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        case 'b':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'r':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'b':
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              case 'u':
                matches |= (1 << (ix - 1));
                if (ix >= length) {
                  return matches;
                }
                switch (s[ix++]) {
                default:
                  break;
                }
                break;
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        case 'g':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      case 'r':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'b':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'w':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'g':
              matches |= (1 << (ix - 1));
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        case 'g':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      case 'u':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'u':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'r':
            matches |= (1 << (ix - 1));
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        case 'b':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'b':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'w':
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              case 'u':
                matches |= (1 << (ix - 1));
                if (ix >= length) {
                  return matches;
                }
                switch (s[ix++]) {
                default:
                  break;
                }
                break;
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      case 'g':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'w':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'b':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'b':
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              case 'b':
                matches |= (1 << (ix - 1));
                if (ix >= length) {
                  return matches;
                }
                switch (s[ix++]) {
                default:
                  break;
                }
                break;
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      case 'b':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'g':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'w':
            matches |= (1 << (ix - 1));
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      default:
        break;
      }
      break;
    case 'u':
      matches |= (1 << (ix - 1));
      if (ix >= length) {
        return matches;
      }
      switch (s[ix++]) {
      case 'w':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'r':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'w':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'r':
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              case 'b':
                matches |= (1 << (ix - 1));
                if (ix >= length) {
                  return matches;
                }
                switch (s[ix++]) {
                default:
                  break;
                }
                break;
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        case 'u':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'r':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'w':
              matches |= (1 << (ix - 1));
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      case 'g':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'b':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'w':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'w':
              matches |= (1 << (ix - 1));
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      case 'u':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'r':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'u':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'u':
              matches |= (1 << (ix - 1));
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              default:
                break;
              }
              break;
            case 'b':
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              case 'g':
                if (ix >= length) {
                  return matches;
                }
                switch (s[ix++]) {
                case 'b':
                  matches |= (1 << (ix - 1));
                  if (ix >= length) {
                    return matches;
                  }
                  switch (s[ix++]) {
                  default:
                    break;
                  }
                  break;
                default:
                  break;
                }
                break;
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          case 'w':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'r':
              matches |= (1 << (ix - 1));
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        case 'b':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'g':
            matches |= (1 << (ix - 1));
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        case 'g':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'w':
            matches |= (1 << (ix - 1));
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      case 'b':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'b':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          default:
            break;
          }
          break;
        case 'u':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'b':
            matches |= (1 << (ix - 1));
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      case 'r':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'r':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'u':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'b':
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              case 'r':
                if (ix >= length) {
                  return matches;
                }
                switch (s[ix++]) {
                case 'u':
                  matches |= (1 << (ix - 1));
                  if (ix >= length) {
                    return matches;
                  }
                  switch (s[ix++]) {
                  default:
                    break;
                  }
                  break;
                default:
                  break;
                }
                break;
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        case 'u':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      default:
        break;
      }
      break;
    default:
      break;
    }
    break;
  case 'b':
    matches |= (1 << (ix - 1));
    if (ix >= length) {
      return matches;
    }
    switch (s[ix++]) {
    case 'r':
      matches |= (1 << (ix - 1));
      if (ix >= length) {
        return matches;
      }
      switch (s[ix++]) {
      case 'u':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'w':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'u':
            matches |= (1 << (ix - 1));
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        case 'g':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'r':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'u':
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              case 'u':
                matches |= (1 << (ix - 1));
                if (ix >= length) {
                  return matches;
                }
                switch (s[ix++]) {
                default:
                  break;
                }
                break;
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      case 'r':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'w':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'w':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'w':
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              case 'w':
                if (ix >= length) {
                  return matches;
                }
                switch (s[ix++]) {
                case 'u':
                  matches |= (1 << (ix - 1));
                  if (ix >= length) {
                    return matches;
                  }
                  switch (s[ix++]) {
                  default:
                    break;
                  }
                  break;
                default:
                  break;
                }
                break;
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        case 'g':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          default:
            break;
          }
          break;
        case 'b':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'w':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'w':
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              case 'u':
                matches |= (1 << (ix - 1));
                if (ix >= length) {
                  return matches;
                }
                switch (s[ix++]) {
                default:
                  break;
                }
                break;
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      case 'b':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'u':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'b':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'r':
              matches |= (1 << (ix - 1));
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      case 'w':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'b':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'b':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'w':
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              case 'g':
                matches |= (1 << (ix - 1));
                if (ix >= length) {
                  return matches;
                }
                switch (s[ix++]) {
                default:
                  break;
                }
                break;
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      case 'g':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'r':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'u':
            matches |= (1 << (ix - 1));
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        case 'g':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'w':
            matches |= (1 << (ix - 1));
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      default:
        break;
      }
      break;
    case 'b':
      matches |= (1 << (ix - 1));
      if (ix >= length) {
        return matches;
      }
      switch (s[ix++]) {
      case 'r':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'u':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'g':
            matches |= (1 << (ix - 1));
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        case 'w':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'g':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'u':
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              case 'r':
                matches |= (1 << (ix - 1));
                if (ix >= length) {
                  return matches;
                }
                switch (s[ix++]) {
                default:
                  break;
                }
                break;
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        case 'g':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'w':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'b':
              matches |= (1 << (ix - 1));
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      case 'g':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'r':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'u':
            matches |= (1 << (ix - 1));
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            default:
              break;
            }
            break;
          case 'b':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'r':
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              case 'b':
                if (ix >= length) {
                  return matches;
                }
                switch (s[ix++]) {
                case 'r':
                  matches |= (1 << (ix - 1));
                  if (ix >= length) {
                    return matches;
                  }
                  switch (s[ix++]) {
                  default:
                    break;
                  }
                  break;
                default:
                  break;
                }
                break;
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        case 'w':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'u':
            matches |= (1 << (ix - 1));
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            default:
              break;
            }
            break;
          case 'r':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'u':
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              case 'u':
                matches |= (1 << (ix - 1));
                if (ix >= length) {
                  return matches;
                }
                switch (s[ix++]) {
                default:
                  break;
                }
                break;
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        case 'u':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      case 'b':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'w':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'b':
            matches |= (1 << (ix - 1));
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        case 'g':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'w':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'r':
              matches |= (1 << (ix - 1));
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      case 'u':
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'r':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'u':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'r':
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              case 'r':
                matches |= (1 << (ix - 1));
                if (ix >= length) {
                  return matches;
                }
                switch (s[ix++]) {
                default:
                  break;
                }
                break;
              default:
                break;
              }
              break;
            case 'u':
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              case 'w':
                if (ix >= length) {
                  return matches;
                }
                switch (s[ix++]) {
                case 'g':
                  matches |= (1 << (ix - 1));
                  if (ix >= length) {
                    return matches;
                  }
                  switch (s[ix++]) {
                  default:
                    break;
                  }
                  break;
                default:
                  break;
                }
                break;
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      case 'w':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'r':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      default:
        break;
      }
      break;
    case 'w':
      matches |= (1 << (ix - 1));
      if (ix >= length) {
        return matches;
      }
      switch (s[ix++]) {
      case 'r':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'g':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          default:
            break;
          }
          break;
        case 'w':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'g':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'b':
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              case 'w':
                matches |= (1 << (ix - 1));
                if (ix >= length) {
                  return matches;
                }
                switch (s[ix++]) {
                default:
                  break;
                }
                break;
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        case 'u':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      case 'w':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'u':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'b':
            matches |= (1 << (ix - 1));
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      case 'u':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'g':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'u':
            matches |= (1 << (ix - 1));
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        case 'r':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          default:
            break;
          }
          break;
        case 'u':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'r':
            matches |= (1 << (ix - 1));
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      case 'g':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'u':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'g':
            matches |= (1 << (ix - 1));
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      case 'b':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'r':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'u':
            matches |= (1 << (ix - 1));
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        case 'w':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      default:
        break;
      }
      break;
    case 'g':
      matches |= (1 << (ix - 1));
      if (ix >= length) {
        return matches;
      }
      switch (s[ix++]) {
      case 'g':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'w':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      case 'r':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'w':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'r':
            matches |= (1 << (ix - 1));
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            default:
              break;
            }
            break;
          case 'g':
            matches |= (1 << (ix - 1));
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'b':
              matches |= (1 << (ix - 1));
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      case 'w':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'b':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'u':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'b':
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              case 'u':
                matches |= (1 << (ix - 1));
                if (ix >= length) {
                  return matches;
                }
                switch (s[ix++]) {
                default:
                  break;
                }
                break;
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        case 'g':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'b':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'b':
              matches |= (1 << (ix - 1));
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        case 'u':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          default:
            break;
          }
          break;
        case 'w':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'g':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'b':
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              case 'b':
                matches |= (1 << (ix - 1));
                if (ix >= length) {
                  return matches;
                }
                switch (s[ix++]) {
                default:
                  break;
                }
                break;
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      case 'u':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'r':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          default:
            break;
          }
          break;
        case 'u':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'w':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'u':
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              case 'u':
                matches |= (1 << (ix - 1));
                if (ix >= length) {
                  return matches;
                }
                switch (s[ix++]) {
                default:
                  break;
                }
                break;
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      case 'b':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        default:
          break;
        }
        break;
      default:
        break;
      }
      break;
    case 'u':
      matches |= (1 << (ix - 1));
      if (ix >= length) {
        return matches;
      }
      switch (s[ix++]) {
      case 'g':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'u':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'b':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'u':
              matches |= (1 << (ix - 1));
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        case 'r':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      case 'u':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'w':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'u':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'b':
              matches |= (1 << (ix - 1));
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        case 'r':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'b':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'g':
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              case 'b':
                matches |= (1 << (ix - 1));
                if (ix >= length) {
                  return matches;
                }
                switch (s[ix++]) {
                default:
                  break;
                }
                break;
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        case 'b':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      case 'r':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'b':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          default:
            break;
          }
          break;
        case 'r':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'g':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'b':
              matches |= (1 << (ix - 1));
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      case 'b':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'g':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'g':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'b':
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              case 'b':
                matches |= (1 << (ix - 1));
                if (ix >= length) {
                  return matches;
                }
                switch (s[ix++]) {
                default:
                  break;
                }
                break;
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      case 'w':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'b':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      default:
        break;
      }
      break;
    default:
      break;
    }
    break;
  case 'g':
    matches |= (1 << (ix - 1));
    if (ix >= length) {
      return matches;
    }
    switch (s[ix++]) {
    case 'r':
      matches |= (1 << (ix - 1));
      if (ix >= length) {
        return matches;
      }
      switch (s[ix++]) {
      case 'w':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'u':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'r':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'b':
              matches |= (1 << (ix - 1));
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        case 'r':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'b':
            matches |= (1 << (ix - 1));
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        case 'b':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'r':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'r':
              matches |= (1 << (ix - 1));
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      case 'r':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'w':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          default:
            break;
          }
          break;
        case 'r':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      case 'u':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'u':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          default:
            break;
          }
          break;
        case 'w':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'r':
            matches |= (1 << (ix - 1));
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      case 'g':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'g':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'b':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'u':
              matches |= (1 << (ix - 1));
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        case 'u':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'u':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'g':
              matches |= (1 << (ix - 1));
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        case 'w':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'g':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'u':
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              case 'r':
                if (ix >= length) {
                  return matches;
                }
                switch (s[ix++]) {
                case 'b':
                  matches |= (1 << (ix - 1));
                  if (ix >= length) {
                    return matches;
                  }
                  switch (s[ix++]) {
                  default:
                    break;
                  }
                  break;
                default:
                  break;
                }
                break;
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      case 'b':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'r':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          default:
            break;
          }
          break;
        case 'w':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      default:
        break;
      }
      break;
    case 'b':
      matches |= (1 << (ix - 1));
      if (ix >= length) {
        return matches;
      }
      switch (s[ix++]) {
      case 'u':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'b':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          default:
            break;
          }
          break;
        case 'u':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'w':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'r':
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              case 'b':
                matches |= (1 << (ix - 1));
                if (ix >= length) {
                  return matches;
                }
                switch (s[ix++]) {
                default:
                  break;
                }
                break;
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        case 'r':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      case 'w':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'g':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'w':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'r':
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              case 'g':
                matches |= (1 << (ix - 1));
                if (ix >= length) {
                  return matches;
                }
                switch (s[ix++]) {
                default:
                  break;
                }
                break;
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      case 'r':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'b':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      case 'g':
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'w':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'w':
            matches |= (1 << (ix - 1));
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      case 'b':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'w':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          default:
            break;
          }
          break;
        case 'g':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'w':
            matches |= (1 << (ix - 1));
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        case 'r':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          default:
            break;
          }
          break;
        case 'u':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'r':
            matches |= (1 << (ix - 1));
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      default:
        break;
      }
      break;
    case 'g':
      matches |= (1 << (ix - 1));
      if (ix >= length) {
        return matches;
      }
      switch (s[ix++]) {
      case 'u':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'r':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          default:
            break;
          }
          break;
        case 'g':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'b':
            matches |= (1 << (ix - 1));
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      case 'g':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'g':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'u':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'r':
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              case 'r':
                matches |= (1 << (ix - 1));
                if (ix >= length) {
                  return matches;
                }
                switch (s[ix++]) {
                default:
                  break;
                }
                break;
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          case 'w':
            matches |= (1 << (ix - 1));
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        case 'b':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'g':
            matches |= (1 << (ix - 1));
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      case 'b':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'r':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'g':
            matches |= (1 << (ix - 1));
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        case 'b':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          default:
            break;
          }
          break;
        case 'w':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      case 'w':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'w':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      case 'r':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'r':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'u':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'b':
              matches |= (1 << (ix - 1));
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              default:
                break;
              }
              break;
            case 'g':
              matches |= (1 << (ix - 1));
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      default:
        break;
      }
      break;
    case 'u':
      matches |= (1 << (ix - 1));
      if (ix >= length) {
        return matches;
      }
      switch (s[ix++]) {
      case 'u':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'b':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'b':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'w':
              matches |= (1 << (ix - 1));
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        case 'w':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          default:
            break;
          }
          break;
        case 'r':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      case 'w':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'r':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          default:
            break;
          }
          break;
        case 'b':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      case 'b':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'b':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'b':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'r':
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              case 'u':
                if (ix >= length) {
                  return matches;
                }
                switch (s[ix++]) {
                case 'g':
                  matches |= (1 << (ix - 1));
                  if (ix >= length) {
                    return matches;
                  }
                  switch (s[ix++]) {
                  default:
                    break;
                  }
                  break;
                default:
                  break;
                }
                break;
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      case 'r':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'r':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'w':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'u':
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              case 'b':
                matches |= (1 << (ix - 1));
                if (ix >= length) {
                  return matches;
                }
                switch (s[ix++]) {
                default:
                  break;
                }
                break;
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        case 'u':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'w':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'g':
              matches |= (1 << (ix - 1));
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        case 'w':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'u':
            matches |= (1 << (ix - 1));
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      case 'g':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'u':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'u':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'g':
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              case 'b':
                matches |= (1 << (ix - 1));
                if (ix >= length) {
                  return matches;
                }
                switch (s[ix++]) {
                default:
                  break;
                }
                break;
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        case 'g':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'w':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'r':
              matches |= (1 << (ix - 1));
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      default:
        break;
      }
      break;
    case 'w':
      matches |= (1 << (ix - 1));
      if (ix >= length) {
        return matches;
      }
      switch (s[ix++]) {
      case 'r':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'w':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'u':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'w':
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              case 'u':
                matches |= (1 << (ix - 1));
                if (ix >= length) {
                  return matches;
                }
                switch (s[ix++]) {
                default:
                  break;
                }
                break;
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      case 'b':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'b':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'r':
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            case 'u':
              if (ix >= length) {
                return matches;
              }
              switch (s[ix++]) {
              case 'u':
                if (ix >= length) {
                  return matches;
                }
                switch (s[ix++]) {
                case 'r':
                  matches |= (1 << (ix - 1));
                  if (ix >= length) {
                    return matches;
                  }
                  switch (s[ix++]) {
                  default:
                    break;
                  }
                  break;
                default:
                  break;
                }
                break;
              default:
                break;
              }
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      case 'g':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'r':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      case 'w':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'u':
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'r':
            matches |= (1 << (ix - 1));
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      case 'u':
        matches |= (1 << (ix - 1));
        if (ix >= length) {
          return matches;
        }
        switch (s[ix++]) {
        case 'g':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          case 'u':
            matches |= (1 << (ix - 1));
            if (ix >= length) {
              return matches;
            }
            switch (s[ix++]) {
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        case 'w':
          matches |= (1 << (ix - 1));
          if (ix >= length) {
            return matches;
          }
          switch (s[ix++]) {
          default:
            break;
          }
          break;
        default:
          break;
        }
        break;
      default:
        break;
      }
      break;
    default:
      break;
    }
    break;
  default:
    break;
  }
  return matches;
}
